#include <bits/stdc++.h>
using namespace std;
#define int long long

int power(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

signed main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> events; 

    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        events.push_back({l, +1});     
        events.push_back({r + 1, -1}); 
    }

    sort(events.begin(), events.end());

    int active = 0;
    for (auto &e : events)
    {
        active += e.second;
        if (active > 2)
        {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
}
