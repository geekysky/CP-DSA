#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    // your code goes here
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        string s;
        cin >> s;

        vector<int> a_fwd(n, 0), b_fwd(n, 0), b_bwd(n, 0), c_bwd(n, 0);

        // two type of combinations
        //  1 . a_FWD * b_bwd
        //  2 . b_fwd * c_bwd
        //  answer is max out of these two

        int temp = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'A')
            {
                temp++;
            }
            else
            {
                temp = 0;
            }

            a_fwd[i] = temp;
        }

        temp = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'B')
            {
                temp++;
            }
            else
            {
                temp = 0;
            }

            b_fwd[i] = temp;
        }

        temp = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == 'B')
            {
                temp++;
            }
            else
            {
                temp = 0;
            }

            b_bwd[i] = temp;
        }

        temp = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == 'C')
            {
                temp++;
            }
            else
            {
                temp = 0;
            }

            c_bwd[i] = temp;
        }

        

        // for (int i = 0; i < n; i++)
        // {
        //     cout << a_fwd[i] << " ";
        // }
        // cout << endl;

        // for (int i = 0; i < n; i++)
        // {
        //     cout << b_bwd[i] << " ";
        // }
        // cout << endl;

        // for (int i = 0; i < n; i++)
        // {
        //     cout << b_fwd[i] << " ";
        // }
        // cout << endl;
        // for (int i = 0; i < n; i++)
        // {
        //     cout << c_bwd[i] << " ";
        // }
        // cout << endl;

        int ans=0;
        for(int i=0;i<n-1;i++){
            ans=max(ans,max((a_fwd[i]*b_bwd[i+1]),(b_fwd[i]*c_bwd[i+1])));
        }

        cout<<ans<<endl;
    }
}