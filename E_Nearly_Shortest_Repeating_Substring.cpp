#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{   
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        string s;
        cin >> s;

        vector<int> factors;
        for (int i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                factors.push_back(i);

                if (i != n / i)
                {
                    factors.push_back(n / i);
                }
            }
        }

        sort(factors.begin(), factors.end());
        int ans = -1;
        for (int i = 0; i < factors.size(); i++)
        {
            int val = factors[i];

            // split s into n/val parts
            // each part is of size val
            bool pos = true;
            int diff = 0;
            for (int j = 0; j < val; j++)
            {

                map<char, int> mp;
                for (int k = j; k < n; k += val)
                {
                    // cout<<s[k]<<" ";
                    mp[s[k]]++;
                }
                // cout<<endl;

                if (mp.size() > 2)
                {
                    pos = false;
                }

                // either all chars are same or just one char is diff
                if (mp.size() == 2)
                {
                    int one = mp.begin()->second;
                    int two = mp.rbegin()->second;
                    
                    //cout<<one<<" "<<two<<endl;
                    if (!(one == n / val - 1 and two == 1) and !(two == n / val - 1 and one == 1))
                    {
                        // bad case
                        // cout<<"bad case"<<endl;
                        pos = false;
                    }
                    else
                    {
                        diff++;
                    }
                }

                if (pos == false)
                {
                    break;
                }
            }

            if (pos == false)
            {
                // next factors to be checked...
                continue;
            }

            if (diff == 0 or diff == 1)
            {
                ans = val;
                break;
            }
        }

        cout << ans << endl;
    }
    return 0;
}