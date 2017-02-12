#include <stdio.h>
#include <string.h>
#include <math.h>
#include "vector.c"

int tonumber(char *string)
{
    char current;
    int n = 0;
    int ints[strlen(string)];

    while (1) {
        current = string[n];

        if (current == '\0') {
            break;
        }

        if (!isdigit(current)) {
            println("Cannot convert to a number");
            exit(3);
        }

        ints[n] = (int)current - 48;

        n++;
    }

    int base = 10;
    int number = 0;
    n = 0;

    while (n < strlen(string)) {
        number += ints[n] * pow((double)base, (double)(strlen(string) - n - 1));
        n++;
    }

    return number;
}

char* tostring(int number)
{
    int base = 10;
    int n = 0;
    int digit;
    vector_t *digits = vector_init(10);

    while (number != 0) {
        int unit = (int)pow((double)base, (double)n + 1.0f);
        digit = number % unit;
        vector_add(v, digit);

        number = number - digit;
        number = number / unit;
    }

    char string[vector_count(digits)];

    for (int i = (vector_count(digits) - 1); i >= 0; i++) {
        // TODO
    }

    return &string;
}

void println(char *string)
{
    printf("%s\n", string);
}