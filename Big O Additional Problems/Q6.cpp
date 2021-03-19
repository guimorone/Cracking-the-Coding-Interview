// square root of a number
int sqrt(int n) {
    for(int guess = 1; guess * guess <= n; guess++) {
        if(guess * guess == n) {
            return guess;
        }
    }

    else return -1;
}

// O(sqrt(n)) => the for loop iterates until guess > sqrt(n), i.e, sqrt(n) times