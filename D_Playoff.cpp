#include <bits/stdc++.h>
using namespace std;
#define int long long

bool possible(int x, string s, int teams) {
    int larger = teams - x;    // teams ranked higher than x
    int smaller = x - 1;       // teams ranked lower than x
    int n = s.size();
    
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            // For a '0', x must lose to a higher ranked team
            if (larger == 0) return false;
            
            // Update counts for next round
            if (larger & 1) {  // if larger count is odd
                larger = (larger - 1) / 2;
                smaller = smaller / 2;
            } else {
                larger = larger / 2;
                smaller = (smaller + 1) / 2;
            }
        } else {  // s[i] == '1'
            // For a '1', x must win against a lower ranked team
            if (smaller == 0) return false;
            
            // Update counts for next round
            if (smaller & 1) {  // if smaller count is odd
                larger = larger / 2;
                smaller = (smaller - 1) / 2;
            } else {
                larger = (larger + 1) / 2;
                smaller = (smaller - 1) / 2;
            }
        }
    }
    return true;
}

signed main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int zero = 0, one = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            zero++;
        }
        else
        {
            one++;
        }
    }
    if (one == n)
    {
        cout << pow(2, n) << "\n";
        return 0;
    }
    else if (zero == n)
    {
        cout << 1 << "\n";
        return 0;
    }
    int teams = pow(2, n);
    int ans = -1;
    for (int x = 2; x < teams; x++)
    {
        // can x be a winner ?
        if (possible(x, s, teams))
        {
            cout<<x<<" ";
        }
    }

    cout << "\n";
    return 0;
}
