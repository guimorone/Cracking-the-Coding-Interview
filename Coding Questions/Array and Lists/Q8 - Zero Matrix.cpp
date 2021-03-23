using namespace std;

/*                                      SOLUTION 1

    Time Complexity => O(m*n*(m + n)) => Where "m" is the number of rows and "n" is the
    number of columns. To iterate through the map we would pass through m*n elements in
    upper-bound.

    Space Complexity => O(m*n) => Maximum map size.

    Resolution => Find the 0's in the matrix and saving them in the map. Then, we
    will iterate through the map seting the rows and columns of the elements in
    the map to 0.
   
*/

void zeroMatrix(vector < vector < int > > &matrix, map < pair <int, int>, bool > &check) {
    const int m = matrix.size(), n = matrix[0].size();

    for(auto const& [key, val] : check) {
        if(val) {
            for(int i = 0; i < m; i++) {
                matrix[i][key.second] = 0;
            }

            for(int i = 0; i < n; i++) {
                matrix[key.first][i] = 0;
            }
        }
    }
}

int main() {
    int m, n;
    cin >> m >> n;
    vector < vector < int > > matrix(m, vector < int > (n));
    map < pair <int, int>, bool > check;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
            if(matrix[i][j] == 0) check[make_pair(i, j)] = true;
        }
    }

    zeroMatrix(matrix, check);
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}

/*                                      SOLUTION 2

    Time Complexity => O(m*n) => Where "m" is the number of rows and "n" is the
    number of columns. This is referring to both for loops in the function below.
    (It is actually O(2m*n) == 0(m*n)).

    Space Complexity => O(m + n) => The size of both arrays (rows and columns).

    Resolution => Similar to the first one, but we use two arrays to optimize time
    and space complexity.
   
*/

void zeroMatrix(vector < vector < int > > &matrix, vector < bool > &rows, vector < bool > &columns) {
    const int m = matrix.size(), n = matrix[0].size();

    for(int i = 0; i < m; i++) {
        if(rows[i]) {
            for(int k = 0; k < n; k++) {
                matrix[i][k] = 0;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        if(columns[i]) {
            for(int k = 0; k < m; k++) {
                matrix[k][i] = 0;
            }
        }
    }
}

int main() {
    int m, n;
    cin >> m >> n;
    vector < vector < int > > matrix(m, vector < int > (n));
    vector < bool > rows(m), columns(n);
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
            if(matrix[i][j] == 0) rows[i] = columns[j] = true;
        }
    }

    zeroMatrix(matrix, rows, columns);
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}