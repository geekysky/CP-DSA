#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {   
        int n;
        cin>>n;
        string s;
        cin >> s;

        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '-')
            {
                mp[1]++;
            }
            else
            {
                mp[-1]++;
            }
        }

        int one = (mp[1] + 1) / 2;
        int two = mp[-1];
        int three = (mp[1]) / 2;
        // cout<<one<<" "<<two<<" "<<three<<"\n";
        cout << one * two * three << "\n";
    }
    return 0;
}