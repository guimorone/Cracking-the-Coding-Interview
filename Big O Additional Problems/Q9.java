// appends a value to an array
int[] copyArray(int[] array) {
    int[] copy = new int[0];
    for(int value : array) {
        copy = appendToNew(copy, value);
    }

    return copy;
}

int[] appendToNew(int[] array, int value) {
    // copy all elements over to new array
    int[] bigger = new int[array.length + 1];
    for(int i = 0; i < array.length; i++) {
        bigger[i] = array[i];
    }

    //add new element
    bigger[bigger.length - 1] = value;
    return bigger;
}

// O(n²), where "n" is the size of "array"
// the first for loop iterates through the array, and "copy" increases its size as ->
// -> the first loop iterates
// When in maximum size, "copy" does a for loop through "n" again in the second function
// Therefore, O(n * n) == O(n²)