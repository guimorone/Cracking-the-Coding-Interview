/*                                      SOLUTION 1

    Time Complexity => O(n²) => where "n" is the size of the string
    Both of the for loops in "isUnique" function iterates through the size of the string

    Space Complexity => O(1) => No additional variables/data structures in the code
*/

using namespace std;

bool isUnique(string s) {
    const int len = s.size();
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < len; j++) {
            if(i != j) {
                if(s[i] == s[j]) return false;
            }
        }
    }

    return true;
}

int main() {
    string s;
    cin >> s;
    cout << isUnique(s);
    
    return 0;
}


/*                                      SOLUTION 2

    Time Complexity => O(n*log n + n) == O(n * log n) => where "n" is the length of the string
    The for loop in the "isUnique" function just iterates through the string
    The biggest runtime is in the string sorting
    
    The space complexity depends on the sorting algorithm
    Mergesort => O(n)
    Quicksort (in-place version) => O(log n)
*/

using namespace std;

bool isUnique(string s) {
    sort(s.begin(), s.end());
    for(int i = 1; i < s.size(); i++) {
        if(s[i] == s[i - 1]) return false;
    }

    return true;
}

int main() {
    string s;
    cin >> s;
    cout << isUnique(s);
    
    return 0;
}

/*                                      SOLUTION 3

    Time Complexity => O(n) => The for loop just iterates one time through the string

    Space Complexity => O(1) => The space needed in the "check" array will never be bigger 
    than 128
*/

using namespace std;

bool isUnique(string s) {
    if(s.size() > 128) return false;
    // 128 == number of unique characters in the alphabet
    vector < bool > check(128);
    for(char x : s){
        if(check[x]) return false;
        check[x] = true;
    }

    return true;
}

int main() {
    string s;
    cin >> s;
    cout << isUnique(s);
    
    return 0;
}