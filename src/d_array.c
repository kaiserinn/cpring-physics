#include "d_array.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_SIZE 16

DArray* da_new(void)
{
    DArray *p = malloc(sizeof(DArray));

    if (p == NULL)
    {
        return NULL;
    }

    p->_alloc = INITIAL_SIZE;
    p->length = 0;

    p->items = calloc(INITIAL_SIZE, sizeof(ArrayValue ));

    if (p->items == NULL)
    {
        free(p);
        return NULL;
    }

    return p;
}

static int da_resize(DArray *da)
{
    da->_alloc *= 2;
    ArrayValue *p = realloc(da->items, da->_alloc);

    if (p == NULL)
    {
        return 0;
    }

    da->items = p;
    return 1;
}

int da_insert(DArray *da, size_t index, ArrayValue value)
{
    if (index > da->length || index < 0)
    {
        printf("index out of bounds");
        return 0;
    }

    if (da->length >= da->_alloc)
    {
        if (!da_resize(da))
        {
            return 0;
        }
    }

    memmove(&da->items[index+1], &da->items[index], (da->length - index) * sizeof(ArrayValue ));

    da->items[index] = value;
    da->length++;

    return 1;
}

int da_append(DArray *da, ArrayValue value)
{
    return da_insert(da, da->length, value);
}

int da_prepend(DArray *da, ArrayValue value)
{
    return da_insert(da, da->length, value);
}

void da_remove(DArray *da, size_t index)
{
    memmove(&da->items[index], &da->items[index+1], (da->length - index) * sizeof(ArrayValue ));
    da->length--;
}

void da_delete(DArray *da)
{
    if (da != NULL)
    {
        free(da->items);
        free(da);
    }
}
