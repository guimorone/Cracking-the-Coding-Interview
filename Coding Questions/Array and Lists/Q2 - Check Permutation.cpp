// It needs to check if whitespaces are significant and if the permutation comparison
// is case sensitive ('A' != 'a')

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    if(permutation(a, b)) cout << "True";
    else cout << "False";

    return 0;
}

/*                                      SOLUTION 1

    Time Complexity => O(a*log(a) + b*log(b)) => where "a" is the length of the first string
    and "b" is the length of the seconde one. Since both are the same size, a = b = n.
    Therefore, O(a*log(a) + b*log(b)) == O(n*log(n)).
    If they don't have the same size, one string is not a permutation of the
    other.
    The runtime just depends on the sorting algorithm.

    The space complexity depends on the sorting algorithm
    Mergesort => O(n)
    Quicksort => O(log n)
*/

bool permutation(string a, string b) {
    int lenA = a.size(), lenB = b.size();
    if(lenA != lenB) return false;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    return a == b;
}

/*                                      SOLUTION 2

    Time Complexity => O(a + b) => where "a" is the length of the first string
    and "b" is the length of the seconde one.
    The first for loop iterates through "a" and the second one does the same for
    "b". Since both are the same size, a = b = n. Therefore, O(a + b) == O(n).
    If they don't have the same size, one string is not a permutation of the
    other.

    Space Complexity => O(1) => The length of the two arrays (countA, countB) will
    always be the same, i.e, O(128 + 128) == O(1)
*/

bool permutation(string a, string b) {
    vector < int > countA(128); // Count the 
    vector < int > countB(128);
    int lenA = a.size(), lenB = b.size();
    if(lenA != lenB) return false;

    for(char i : a) {
        countA[i]++;
    }

    for(char i : b) {
        countB[i]++;
    }

    return countA == countB;
}