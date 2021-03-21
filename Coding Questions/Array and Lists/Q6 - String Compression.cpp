// The problem is case sensitive.
using namespace std;

int main() {
    string s;
    cin >> s;
    cout << stringCompression(s);
    return 0;
}

/*                                      SOLUTION 1

    Time Complexity => O(n) => Where "n" is the string length. The for loop just iterates
    through the string one time. (Depends on the "+=" or "append" complexity, if they are
    O(n) as well, then the time complexity will be O(n²))

    Space Complexity => O(n) => In order to create the new string "aux", we need to
    allocate a dynamic amount of memory, based on the string length.

    Resolution => Just compare the current character with the previous one and count 
    until they get different.
*/

string stringCompression(string s) {
    int len = s.size();
    if(len < 1) return s;
    string aux = "";
    aux.push_back(s[0]);
    int count = 1;
    for(int i = 1; i < len; i++) {
        if(s[i] != s[i - 1]) {
            aux.append(to_string(count));
            aux.push_back(s[i]);
            count = 1;
        } else {
            count++;
        }
    }
    aux.append(to_string(count));

    return (aux.size() < s.size() ? aux : s);
}