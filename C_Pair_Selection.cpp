#include<bits/stdc++.h>
using namespace std;
#define lld long double
#define int long long int 

bool ratio_exists(lld mid, vector<int> &a, vector<int> &b, int n, int k){
    // Calculate ai - mid * bi for each i
    vector<lld> transformed;
    for(int i = 0; i < n; i++){
        transformed.push_back(a[i] - (mid * b[i]));
    }

    // Sort the transformed vector in descending order
    sort(transformed.begin(), transformed.end(), greater<lld>());

    // Calculate the sum of the largest n-k elements
    lld sum = 0;
    for(int i = 0; i < k; i++){
        sum += transformed[i];
    }

    // Check if this sum is non-negative
    return sum >= 0;
}

signed main(){
    int n, k;
    cin >> n >> k;

    vector<int> a(n), b(n);

    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }

    // Initialize binary search range
    lld low = 0, high = 1e18;

    // Perform binary search to find the maximum possible mid
    for(int i = 0; i < 100; i++){
        lld mid = (low + high) / 2;

        if(ratio_exists(mid, a, b, n, k)){
            low = mid;
        } else {
            high = mid;
        }
    }

    cout << setprecision(7) << fixed << low << "\n";

    return 0;
}
