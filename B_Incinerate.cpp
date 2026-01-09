#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        int h[n], p[n];
        for (int i = 0; i < n; i++) {
            cin >> h[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }

        vector<pair<int, int>> health_power;

        for (int i = 0; i < n; i++) {
            health_power.push_back({h[i], p[i]});
        }

        sort(health_power.begin(), health_power.end());

        int tot_damage = k;
        int dead = 0;
        
        vector<int> min_power_range(n);
        int minp=INT_MAX;

        for(int i=n-1;i>=0;i--){
            minp=min(minp,health_power[i].second);

            min_power_range[i]=minp;
        }

        while (k > 0) {
            auto it = upper_bound(health_power.begin(), health_power.end(), make_pair(tot_damage, INT_MAX));
            dead = it - health_power.begin();

            if (dead == n) break; 
            
            //ab it se last tak - matlab jitne alive hai unme se sabse min power find karne 
            //k liye suffix array min_power_range banaya hai to access min power of range 
            //in O(1)

            //so directly min_power_range[it] kiya to mil jayega min till end 
            k-=min_power_range[dead];

            tot_damage+=k;
            

            
        }

        if (dead == n)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }

    return 0;
}
