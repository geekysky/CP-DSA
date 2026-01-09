#include <bits/stdc++.h>
using namespace std;
#define int long long int

void change_value(vector<string> &matrix, int x, int y) {
    if (matrix[x][y] == '1') {
        matrix[x][y] = '2';
    } else {
        matrix[x][y] = '1';
    }
}

signed main() {
    int t;
    cin >> t;

    while (t--) {
        int x=0,y=0;
        vector<string> matrix;
        
        for (int i = 0; i < 9; i++) {
            string s;
            cin >> s;
            matrix.push_back(s);
        }

        change_value(matrix,0,0);
        change_value(matrix,1,3);
        change_value(matrix,2,6);
        change_value(matrix,3,1);
        change_value(matrix,4,4);
        change_value(matrix,5,7);
        change_value(matrix,6,2);
        change_value(matrix,7,5);
        change_value(matrix,8,8);

        for (int i = 0; i < 9; i++) {
            cout << matrix[i] << endl;
        }
        
    }

    return 0;
}
