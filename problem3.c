#include <math.h>

int isprime(int n)
{
    if (n < 2) {
        return 0;
    }

    int limit = ceil(sqrt((double)n));
    int current = 2;

    while (current < limit) {
        if ((n % current) == 0) {
            return 0;
        }

        current++;
    }

    return 1;
}

int problem3(long n)
{
    int largest = 0;

    while (1) {
        int prime = 1;

        while (1) {
            if (!isprime(++prime)) {
                continue;
            }

            if (n % prime == 0) {
                n = n / prime;

                if (prime > largest) {
                    largest = prime;
                }

                break;
            }
        }

        if (isprime(n)) {
            if (n > largest) {
                largest = n;
            }

            break;
        }
    }

    return largest;
}
