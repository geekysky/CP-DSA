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

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int ans = 0;
        int s=1e9,t=1e9;
        for (int i = 0; i < n; i++)
        {
            int ele=arr[i];

            if(ele<=s and ele<=t){
                if(s<=t){
                    s=ele;
                }
                else{
                    t=ele;
                }
            }
            else{
                
            }

        }

        cout << ans << endl;
    }

    return 0;
}
