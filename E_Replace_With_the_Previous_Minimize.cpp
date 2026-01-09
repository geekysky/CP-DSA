#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;
        int rem = k;

        set<char> last_processed;
        vector<char> change(26);
        for (int i = 0; i < 26; i++) {
            change[i] = ('a' + i);
        }

        for (int i = 0; i < n; i++) {
            if (s[i] != 'a') {
                if (last_processed.empty()) {
                    int possible = min(rem, (s[i] - 'a') * 1LL);
                    change[s[i] - 'a'] = ('a' + (s[i] - 'a' - possible));
                    if (possible > 0) {
                        last_processed.insert(s[i]);
                    }
                    rem -= possible;
                }
                else if (s[i] > *last_processed.rbegin()) {
                    int possible = min(rem, (s[i] - *last_processed.rbegin()) * 1LL);
                    change[s[i] - 'a'] = change[s[i]-possible-'a'];
                    if (possible > 0) {
                        last_processed.insert(s[i]);
                    }
                    rem -= possible;
                }
                else {
                    auto it = last_processed.upper_bound(s[i]);
                    if (it != last_processed.end()) {
                        if(change[*it - 'a']<change[s[i] - 'a']){
                            change[s[i] - 'a'] = change[*it - 'a'];
                        }
                    }
                }
            }
        }

        string ans = "";
        for (int i = 0; i < n; i++) {
            ans += change[s[i] - 'a'];
        }

        cout << ans << "\n";
    }
    return 0;
}