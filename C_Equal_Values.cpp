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

        int ans = LLONG_MAX;
        // at most 2 operations are needed to make all elements equal

        int beg = 0, end = 0;
       
        for (int i = 0; i < n; i++)
        {   
            int j=i;
            while(arr[j+1]==arr[i] and j+1<n){
                j++;
            }

            ans=min(ans,(i+n-1-j)*arr[i]);
            i=j;
        }

        //ans = min(((beg + n - 1 - end) * arr[beg]), ans);

        cout << ans << endl;
    }
    return 0;
}