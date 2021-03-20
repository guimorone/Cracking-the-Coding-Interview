using namespace std;

int main() {
    string s;
    int n;
    getline(cin, s);
    cin >> n;
    // Trim -> remove irrelevant whitespaces
    
    // leading
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == ' ') {
            s.erase(i, 1);
            i--;
        } else break;
    }

    // Since we have the real length of the string,
    // We don't need to remove the trailing spaces from the string
    cout << URLify(s, n);

    return 0;
}

/*                                      SOLUTION 1

    Time Complexity => O(n) => Where "n" is the string length.
    The for loop just iterates through "s".

    Space Complexity => O(n) => We've used the new string "newStr" to allocate
    extra space.
*/

string URLify(string s, int n) {
    string newStr = "";
    int rightWhiteSpaces = s.size() - n;
    // Trailing trim
    s.erase(s.end() - rightWhiteSpaces, s.end());
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == ' ') {
            newStr += "%20";
        } else newStr += s[i];
    }

    return newStr;
}

/*                                      SOLUTION 2
                                         in-place

    Time Complexity => O(n) => Where "n" is the string length.
    The for loop just iterates through "s".

    Space Complexity => O(1) => No additional data structures used.
    * Actually this depends on the "replace" method implementation. *

*/

string URLify(string s, int n) {
    for(int i = 0; i < n; i++) {
        if(s[i] == ' ') {
            s.replace(i, 1, "%20");
            n += 2;
        }
    }

    return s;
}