#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        // 1) sort & dedupe
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());

        // 2) build events for [a[i]+1, a[i]+n]
        //    +1 at start, -1 just after end
        vector<pair<ll,int>> events;
        events.reserve(a.size()*2);
        for (ll x : a){
            events.emplace_back(x + 1,    +1);
            events.emplace_back(x + n + 1, -1);
        }

        // 3) sweep
        sort(events.begin(), events.end());
        int cur = 0, best = 0;
        for (auto &ev : events){
            cur += ev.second;
            best = max(best, cur);
        }

        cout << best << "\n";
    }
    return 0;
}
