int problem1() {
    int n = 0, sum = 0;

    while (++n < 1000) {
        if ((n % 5 == 0) || (n % 3 == 0)) {
            sum += n;
        }
    }

    return sum;
}