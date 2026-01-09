#include<bits/stdc++.h>
using namespace std;
#define int long long int 

// Recursive function to add two matrices
void addition(int one[][100], int two[][100], int result[][100], int r, int c, int i, int j) {
    // Base case: if we've processed all rows and columns
    if (i < 0) return;
    if (j < 0) {
        // Move to the previous row
        addition(one, two, result, r, c, i - 1, c - 1);
        return;
    }
    
    // Add the current elements of the matrices
    result[i][j] = one[i][j] + two[i][j];
    
    // Move to the next element in the row (previous column)
    addition(one, two, result, r, c, i, j - 1);
}

signed main() {
    int r, c;
    cin >> r >> c;

    // Define matrices with a fixed maximum size
    int one[100][100], two[100][100], result[100][100];

    // Input matrix one
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> one[i][j];
        }
    }

    // Input matrix two
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> two[i][j];
        }
    }

    // Call the recursive addition function starting from the last element
    addition(one, two, result, r, c, r - 1, c - 1);

    // Output the result matrix
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
