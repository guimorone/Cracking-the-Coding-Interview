// Assuming it is clockwise

using namespace std;

int main() {
    int n;
    do {
        cin >> n;
    } while(!n);
    vector < vector < int > > matrix(n, vector < int > (n));
    for(int i = 0 i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    rotateMatrix(matrix);
    for(int i = 0 i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << matrix[i][j];
        }
    }
    return 0;
}

/*                                      SOLUTION 1

    Time Complexity => O(n²) => Where "n" is the matrix length. To solve it, we have to
    touch all the n² elements in the matrix.

    Space Complexity => O(1) => Question done in-place without using extra space.

    Resolution => Ex:  1  2  3   Reverse rows    7  8  9    Transpose   7  4  1
                       4  5  6   ------------>   4  5  6    -------->   8  5  2
                       7  8  9                   1  2  3                9  6  3       
*/

void rotateMatrix(vector < vector < int > > &matrix) {
    // n x n
    const int len = (int) matrix.size();

    // reverse rows
    for(int i = 0; i < len/2; i++){
        swap(matrix[i], matrix[len - i - 1]);
    }

    // transpose
    for(int i = 0; i < len; i++){
        for(int j = i; j < len; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}