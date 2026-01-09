#include <bits/stdc++.h>
using namespace std;
#define ll long long

int all_sum(int num, int target) {
    int ans = 0;
    int mult = num;
    while (mult <= target) {
        ans += mult;
        mult += num;
    }
    return ans;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int curr = INT_MIN;
        int prev = -1;
        for (int i = 2; i <= n; i++) {
            int temp = all_sum(i, n);

            if (temp > curr) {
                curr = temp;
                prev = i;
            }
        }

        cout << prev << "\n";
    }
    return 0;
}
