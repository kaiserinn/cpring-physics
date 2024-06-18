#ifndef D_ARRAY_H
#define D_ARRAY_H
 
#include <stdlib.h>

typedef void *ArrayValue ;

typedef struct DArray {
    size_t _alloc;
    size_t length;
    ArrayValue *items;
} DArray;

DArray* da_new(void);

int da_insert(DArray *da, size_t index, ArrayValue value);

int da_append(DArray *da, ArrayValue value);

int da_append(DArray *da, ArrayValue value);

void da_delete(DArray *da);

void da_remove(DArray *da, size_t index);

#endif // ! D_ARRAY_H
 
