#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<long long> books(n);
    long long sumT = 0, maxT = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> books[i];
        sumT += books[i];
        maxT = max(maxT, books[i]);
    }

    cout << max(sumT, 2 * maxT) << endl;
    return 0;
}
