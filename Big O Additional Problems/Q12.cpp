// Intersection of two arrays
int intersection(int[] a, int[] b) {
    mergesort(b);
    int intersect = 0;

    for(int x : a) {
        if(binarySearch(b, x) >= 0) {
            intersect++;
        }
    }

    return intersect;
}

// O(b*log b + a * log b) => O(b*log b) = mergesort
// O(a * log b) => O(log b) = binarySearch for each element in a