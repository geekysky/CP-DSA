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

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        int m1 = 0, m2 = 0;
        int x = 0, y = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 1 and (b[i] == 0 or b[i] == -1))
            {
                m1++;
            }
            else if (b[i] == 1 and (a[i] == 0 or a[i] == -1))
            {
                m2++;
            }
            else if (a[i] == -1 and b[i] == -1)
            {
                y++;
            }
            else if (a[i] == 1 and b[i] == 1)
            {
                x++;
            }
        }
        
        //in worst case x+y == n
        //why o(1) when y can do it in o(n)...hehe
        while(x--){
            if(m1>m2){
                m2++;
            }
            else{
                m1++;
            }
        }

        while(y--){
            if(m1>m2){
                m1--;
            }
            else{
                m2--;
            }
        }

        cout<<min(m1,m2)<<endl;
    }
    return 0;
}