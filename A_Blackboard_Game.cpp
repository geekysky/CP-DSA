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
        cin >> n;

        if (n == 1)
        {
            cout << "Alice" << endl;
            continue;
        }
        vector<int> taken(n, -1);
        for (int i = 0; i < n - 1; i++)
        {
            if (taken[i] == -1)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (taken[j] == -1 and (i + j) % 4 == 3)
                    {
                        taken[i] = 0;
                        taken[j] = 0;

                        break;
                    }
                }
            }
        }

        bool al = false;
        for (int i = 0; i < n; i++)
        {
            if (taken[i] == -1)
            {
                al = true;
                break;
            }
        }
        
        // for(auto x:taken){
        //     cout<<x<<" ";
        // }
        // cout<<endl;

        if (al)
        {
            cout << "Alice" << endl;
        }
        else
        {
            cout << "Bob" << endl;
        }
    }
    return 0;
}