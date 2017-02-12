#include <math.h>

int problem4(long n)
{
    char candidate[n];
    int i = 0;

    while (i < n) {
        candidate[i] = '9';
        i++;
    }

    int a = tonumber(candidate);
    int b = tonumber(candidate);

    int product = a * b;


}
