#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    string s;
    cin >> s;

    // vvv...o...vvv
    if (s.size() <= 4)
    {
        cout << 0 << endl;
        return 0;
    }

    int n = s.size();
    vector<int> pref(n), suff(n);

    int v_cnt = (s[0] == 'v' ? 1 : 0);
    pref[0] = 0;
    for (int i = 1; i < n; i++)
    {
        if (s[i] == 'v')
        {
            v_cnt++;
        }

        // cout<<v_cnt<<" ";
        if (s[i] == 'o')
        {
            v_cnt = 0;
            pref[i] = pref[i - 1];
        }

        else
        {
            if (v_cnt >= 2)
            {
                pref[i] = pref[i - 1] + 1;
            }
            else if (v_cnt == 1 and s[i] == 'v')
            {
                pref[i] = pref[i - 1];
            }
        }
    }
    // cout<<"\n";
    // for (auto x : pref)
    // {
    //     cout << x << " ";
    // }
    // cout << endl;

    v_cnt = (s.back() == 'v' ? 1 : 0);
    for (int i = n - 2; i >= 0; i--)
    {
        if (s[i] == 'v')
        {
            v_cnt++;
        }

        // cout<<v_cnt<<" ";
        if (s[i] == 'o')
        {
            v_cnt = 0;
            suff[i] = suff[i + 1];
        }

        else
        {
            if (v_cnt >= 2)
            {
                suff[i] = suff[i + 1] + 1;
            }
            else if (v_cnt == 1 and s[i] == 'v')
            {
                suff[i] = suff[i + 1];
            }
        }
    }

    // for(auto x:suff){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    
    int ans=0;
    for(int i=0;i<n;i++){
        if(s[i]=='o'){
            ans += (pref[i]*suff[i]);
        }
    }

    cout<<ans<<endl;

    return 0;
}