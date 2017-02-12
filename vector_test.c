#include "vector.c"
#include <assert.h>
#include <stdio.h>

int main()
{
    vector_t *v = vector_init(0);

    assert(vector_count(v) == 0);

    vector_add(v, 'a');

    assert(vector_count(v) == 1);

    assert((char)vector_get(v, 0) == 'a');

    vector_add(v, 'b');
    vector_add(v, 'c');
    vector_add(v, 'd');
    vector_add(v, 'e');
    vector_add(v, 'f');
    vector_add(v, 'g');

    assert(vector_count(v) == 7);
    assert((char)vector_get(v, 1) == 'b');
    assert((char)vector_get(v, 2) == 'c');
    assert((char)vector_get(v, 3) == 'd');
    assert((char)vector_get(v, 4) == 'e');
    assert((char)vector_get(v, 5) == 'f');
    assert((char)vector_get(v, 6) == 'g');

    vector_remove(v, 3);

    assert(vector_count(v) == 6);
    assert((char)vector_get(v, 0) == 'a');
    assert((char)vector_get(v, 1) == 'b');
    assert((char)vector_get(v, 2) == 'c');
    assert((char)vector_get(v, 3) == 'e');
    assert((char)vector_get(v, 4) == 'f');
    assert((char)vector_get(v, 5) == 'g');

    vector_t *slice1 = vector_slice(v, 0, 3);

    assert(vector_count(slice1) == 3);
    assert((char)vector_get(slice1, 0) == 'a');
    assert((char)vector_get(slice1, 1) == 'b');
    assert((char)vector_get(slice1, 2) == 'c');

    vector_t *slice2 = vector_slice(v, 3, 3);

    assert(vector_count(slice2) == 3);
    assert((char)vector_get(slice2, 0) == 'e');
    assert((char)vector_get(slice2, 1) == 'f');
    assert((char)vector_get(slice2, 2) == 'g');

    vector_t *slice3 = vector_slice(v, 0, 1);

    assert(vector_count(slice3) == 1);
    assert((char)vector_get(slice3, 0) == 'a');

    vector_t *slice4 = vector_slice(v, 5, 1);

    assert(vector_count(slice4) == 1);
    assert((char)vector_get(slice4, 0) == 'g');

    printf("Done!");
}