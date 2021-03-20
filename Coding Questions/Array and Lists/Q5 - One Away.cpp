using namespace std;

int main() {

    string a, b;
    cin >> a >> b;
    bool ans = oneAway(a, b);
    if(ans) cout << "True";
    else cout << "False";

    return 0;
}

/*                                      SOLUTION 1

    Time Complexity => O(n) => Where "n" is either the length of the "a" string
    or the length of the "b" string. Since the maximum difference allowed on both
    is 1, abs(length(a) - length(b)) <= 1 => Roughly, length(a) == length(b). Therefore,
    as the for loop in the function iterates through the string twice, the time complexity 
    is O(n + n), i.e, O(n).

    Space Complexity => O(1) => No additional data structures.

    Resolution => As insert and remove actions are similar, we can divide the function into two.
    In case of replacement, length(a) must be equals to length(b), and both of them must be
    different only in one place. So, if we find more than one difference, they are not one edit
    away.
    Otherwise, in case of insertion or removal, (length(a) - length(b)) must be equal to 1. As
    with replacement, both of them must be different only in one place. So, if we find more
    than one difference, they are not one edit away.
*/

bool oneAway(string a, string b) {
    if(a == b) return true;
    int lenA = a.size(), lenB = b.size();
    if(abs(lenA - lenB) > 1) return false;
    
    // insert, remove or replace

    int count = 0;
    if(lenA != lenB) {
        // insert or remove
        count++; 
        bool check = false;
        int n = min(lenA, lenB);
        for(int i = 0; i < n; i++) {
            if(check) {
                if(lenA > lenB) {
                    if(a[i + 1] != b[i]) {
                        count++;
                        break;
                    }
                } else {
                   if(a[i] != b[i + 1]) {
                        count++;
                        break;
                    } 
                }
            } else{
               if(a[i] != b[i]) check = true;
            }
        }
    } else {
        // replace
        for(int i = 0; i < lenA; i++) {
            if(a[i] != b[i]) count++;
        }
    }

    

    return count <= 1;
}

/*                                      SOLUTION 2

    The same of solution 1, but we are not dividing the function here.
*/

bool oneAway(string a, string b) {
    if(abs(a.size() - b.size()) > 1) return false;

    // Get shorter and longer string
    string s1 = a.size() < b.size() ? a : b;
    string s2 = a.size() < b.size() ? b : a;

    int index1 = 0, index2 = 0;
    bool foundDifference = false;

    while(index2 < s2.size() && index1 < s1.size()) {
        if(s1[index1] != s2[index2]) {
            // Ensure that this is the first difference found
            if(foundDifference) return false;
            foundDifference = true;

            // On replace, move shorter pointer
            if(s1.size() == s2.size()) index1++;
        } else {
            index1++; // If matching, move shorter pointer
        }
        index2++; // Always move pointer for longer string
    }

    return true;
}