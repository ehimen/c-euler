#include <stdio.h>

int problem2(long max) {
    int n1 = 1;
    int n2 = 2;
    int current;
    int sum = 2;

    do {
        current = n1 + n2;

        if (current % 2 == 0) {
            sum += current;
        }

        n1 = n2;
        n2 = current;
    } while(current < max);

    return sum;
}