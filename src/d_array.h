#ifndef D_ARRAY_H
#define D_ARRAY_H
 
#include <stdlib.h>

typedef struct DArray {
    size_t _alloc;
    size_t length;
    void **items;
} DArray;

DArray* da_new(void);

int da_insert(DArray *da, size_t index, void *value);

int da_append(DArray *da, void *value);

int da_append(DArray *da, void *value);

void da_delete(DArray *da);

void da_remove(DArray *da, size_t index);

#endif // ! D_ARRAY_H
 
