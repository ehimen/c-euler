#include <stdlib.h>
#include <string.h>

typedef struct {
    int *pointer;
    int head;
    int size;
} vector_t;

void* vector_alloc(int amount)
{
    void *pointer = malloc(sizeof(int) * amount);

    if (pointer == '\0') {
        printf("ERROR: malloc failed");
        exit(1);
    }

    return pointer;
}

vector_t* vector_init(int size)
{
    if (size < 1) {
        size = 1;
    }

    int *pointer = (int *)vector_alloc(size);

    vector_t *v = (vector_t *)malloc(sizeof(vector_t));

    v->pointer = pointer;
    v->head = 0;
    v->size = size;

    return v;
}

void vector_add(vector_t *v, void *item)
{
    if (v->head >= v->size) {
        int *pointer = (int *)memcpy(vector_alloc(v->size * 2), v->pointer, v->size * sizeof(int));
        v->pointer = pointer;
        v->size *= 2;
    }

    int head = v->head;

    v->pointer[head] = (int *)item;
    v->head = v->head + 1;
}

void* vector_get(vector_t *v, int index)
{
    return v->pointer[index];
}

vector_t* vector_slice(vector_t *v, int start, int length)
{
    vector_t *new = vector_init(length);

    int end = start + length;

    for (int i = start; i < end; i++) {
        vector_add(new, vector_get(v, i));
    }

    return new;
}

void vector_remove(vector_t *v, int index)
{
    int i;

    for (i = index; i < v->head; i++) {
        v->pointer[i] = v->pointer[i + 1];
    }

    v->head--;
}

int vector_count(vector_t *v)
{
    return v->head;
}