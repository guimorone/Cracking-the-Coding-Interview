// Square root of a number
int sqrt(int n) {
    return sqrt_helper(n, 1, n);
}

int sqrt_helper(int n, int min, int max) {
    if(max < min) return -1; //no square root

    int guess = (min + max)/2;
    if(guess * guess == n) {
        return guess;
    } else if(guess * guess < n) { // too low
        return sqrt_helper(n, guess + 1, max); // try higher
    } else { // too high
        return sqrt_helper(n, min, guess - 1); // try lower
    }
}

// O(log n) => similar to a Binary Search