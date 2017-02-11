#include <stdio.h>
#include <string.h>
#include <math.h>

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

void println(char *string)
{
    printf("%s\n", string);
}