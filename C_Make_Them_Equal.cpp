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
        char ch;
        cin >> n >> ch;

        string s;
        cin >> s;
        
        int wrong=0;
        int lst_idx;
        for (int i = 0; i < n; i++)
        {
            if (s[i] != ch)
            {
                wrong++;

                lst_idx=i;
            }
        }

        if (wrong == 1)
        {
            cout << 1 << endl;
            if (lst_idx == n-1)
            {
                cout << n-1 << endl;
            }
            else
            {
                cout << n << endl;
            }

            continue;
        }
        else if (wrong == 0)
        {
            cout << 0 << endl;
            continue;
        }

        int ans = 0;
        for (int x = 2; x <= n; x++)
        {
            int cnt = 1;
            for (int j = x; j <= n; j += x)
            {
                if(s[j-1]!=ch){
                    cnt=0;
                    break;
                }
            }

            if (cnt == 1)
            {
                ans = x;
                break;
            }
        }

        if (ans)
        {
            cout << 1 << endl;
            cout << ans << endl;
        }
        else
        {
            cout << 2 << endl;
            cout << n << " " << n - 1 << endl;
        }
    }
    return 0;
}