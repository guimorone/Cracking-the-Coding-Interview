// a % b
int mod(int a, int b) {
    if(b <= 0) return -1;
    int div = a / b;
    return a - div * b;
}

// O(1) It does a constant amount of work