#include "d_array.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_SIZE 16

DArray* da_new(void)
{
    DArray *p = malloc(sizeof(DArray));
    if (p == NULL)
        return NULL;

    p->_alloc = INITIAL_SIZE;
    p->length = 0;

    p->items = calloc(INITIAL_SIZE, sizeof(void *));
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
    void *p = realloc(da->items, da->_alloc);
    if (p == NULL)
        return 0;
    da->items = p;
    return 1;
}

int da_insert(DArray *da, size_t index, void *value)
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
    memmove(&da->items[index+1], &da->items[index], (da->length - index) * sizeof(void *));
    da->items[index] = value;
    da->length++;
    return 1;
}

int da_append(DArray *da, void *value)
{
    return da_insert(da, da->length, value);
}

int da_prepend(DArray *da, void *value)
{
    return da_insert(da, da->length, value);
}

void da_remove(DArray *da, size_t index)
{
    memmove(&da->items[index], &da->items[index+1], (da->length - index) * sizeof(void *));
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
