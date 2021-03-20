using namespace std;

// Considering that special characters are not significant
// Also considering that it is not case sensitive

string removeSpecialChar(string s) {
        // se n for a - z
        // não tem diferença de maiúsculo para minúsculo
        int tam = 0;
        for(int i = 0; i < (int) s.size(); i++){
            if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
                s[tam++] = tolower(s[i]);
            }
        }
        
        return s.substr(0, tam);
}

int main() {
    string s;
    getline(cin, s);
    s = removeSpecialChar(s);
    bool ans = palindromePermutation(s);
    if(ans) cout << "True";
    else cout << "False";
    return 0;
}

/*                                      SOLUTION 1

    Time Complexity => O(n) => Where "n" is the string length.
    The for loop just iterates through "s".
    Roughly it would be: O(2n) == O(n).

    Space Complexity => O(1).
    The length of the "count" array will always be the same, i.e, O(128) == O(1).
    
*/


/*  
    If the string length is an even number, then the number of times 
    each letter appears has to be even as well.

    Else if the string length is an odd number, then it must have one, and just one,
    letter that appears in an odd number of times. 
    The number of times each of the remaining letters appears has to be even.
*/

bool palindromePermutation(string s) {
    string aux = s;
    vector < int > count(128);
    if(s.size() % 2 == 0) {
        for(auto x : s) {
            s[x]++;
        }

        for(auto x : s) {
            if(s[x] % 2 == 1) return false;
        }

        return true;
    } else {
        bool oddFounded = false;
        char oddLetter = ' ';
        for(auto x : s) {
            s[x]++;
        }
        for(auto x : s) {
            if(s[x] % 2 == 1 && !oddFounded) {
                oddFounded = true;
                oddLetter = x;
            }
            else if(x != oddLetter && s[x] % 2 == 1 && oddFounded) return false;
        }

        return oddFounded;
    }

}