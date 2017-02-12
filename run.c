#include <stdlib.h>
#include "util.c"
#include "problem1.c"
#include "problem2.c"
#include "problem3.c"
#include "problem4.c"

int main(int argc, char *argv[])
{
    if (argc < 2) {
        println("not enough args, expects problem num");
        exit(1);
    }

    int problem = tonumber(argv[1]);
    int answer;

    long problemArg1;

    switch (problem) {
        case 1:
            answer = problem1();
            break;
        case 2:
            problemArg1 = 4000000;

            if (argc == 3) {
                problemArg1 = tonumber(argv[2]);
            }

            answer = problem2(problemArg1);
            break;

        case 3:
            problemArg1 = 600851475143;

            if (argc == 3) {
                problemArg1 = tonumber(argv[2]);
            }

            answer = problem3(problemArg1);
            break;

        case 4:
            problemArg1 = 3;

            if (argc == 3) {
                problemArg1 = tonumber(argv[2]);
            }

            answer = problem4(problemArg1);
            break;
        default:
            println("Unknown problem number");
            exit(2);
    }

    printf("%d\n", answer);
}