#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, s;
        cin >> n >> s;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        
        if(arr[0]>= s){
            //all on the right side 
            cout<<abs(arr.back() - s)<<endl;
            continue;
        }
        else if(arr.back() <= s){
            cout<<abs(s - arr[0])<<endl;
            continue;
        }
        
        // smaller wala do baar and bada wala ek baar
        int sma = abs(s - arr[0]);
        int gre = abs(arr.back() - s);

        cout << 2 * min(sma,gre) + max(sma,gre) << endl;
    }
    return 0;
}