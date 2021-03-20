using namespace std;

int main() {

    string a, b;
    cin >> a >> b;
    bool ans = oneAway(a, b);
    if(ans) cout << "True";
    else cout << "False";

    return 0;
}

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