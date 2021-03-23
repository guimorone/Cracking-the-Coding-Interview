/*                                      SOLUTION 
    
    Time Complexity => Depends on the runtime of "isSubstring" function. 
    Normally, it runs in O(A + B), where "A" and "B" are the lengths of the strings. 
    Therefore, the runtime is O(n).

    Space Complexity => O(1) => No extra space used.
   
    Resolution => If we imagine that s2 is a rotation of s1, then we can ask where the
    rotation point is. For example, if you rotate "waterbottle" after "way", you get
    erbottlewat. In a rotation, we cut s1 into two parts, x and y, and rearrange them
    to get s2.
    s1 = xy = waterbottle
    x = wat
    y = erbottle
    s2 = yx = erbottlewat
    So, we need to check if there is a way to split s1 into x and y such that xy = s1 
    and yx = s2. Regardless of where the division between x and y is, we can see that 
    yx will always be a substring of xyxy. That is, s2 will always be a substring of s1s1.
*/

using namespace std;

bool stringRotation(string s1, string s2) {
    const int len1 = s1.size(), len2 = s2.size();

    // In order for one string to be a rotation of another, they must have the same size.
    if(len1 == len2 && len1 > 0) {
        string s1s1 = s1 + s1;

        // find == isSubstring
        if(s1s1.find(s2) != string::npos) return true;
    }

    return false;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    bool ans = stringRotation(s1, s2);
    if(ans) cout << "True";
    else cout << "False";
    return 0;
}