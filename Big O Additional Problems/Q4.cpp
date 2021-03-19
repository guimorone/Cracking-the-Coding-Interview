// integer division
int div(int a, int b) {
    int count = 0;
    int sum = b;
    while(sum <= a) {
        sum += b;
        count++;
    }

    return count;
}

// The while loop iterates "count" times, therefore, O(a/b)