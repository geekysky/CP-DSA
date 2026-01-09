#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main() {
    int n, m;
    cin >> n >> m;
    
    int minimum;
    int maximum = (n - m + 1) * (n - m) / 2;
    int rem = n % m;
   
    if (rem == 0) {
        minimum = (m * (n/m) * (n/m - 1)) / 2;
    } else {
        int each = n/m;
        // First approach: distribute rem across teams
        int min1 = (m-rem) * (each * (each-1))/2 + 
                  rem * ((each+1) * each)/2;
        
        // Second approach: all rem in one team
        int min2 = (m-1) * (each * (each-1))/2 + 
                  ((each + rem) * (each + rem - 1))/2;
                  
        minimum = min(min1, min2);
    }

    cout << minimum << " " << maximum << "\n";
    return 0;
}