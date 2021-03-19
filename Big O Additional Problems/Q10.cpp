// sums the digits in a number
int sumDigits(int n) {
    int sum = 0;
    while(n > 0) {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

// The runtime will be the number of digits in the number, i.e, O(log n)
// Regardless of the log base