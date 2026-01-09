#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        // Using a set of pairs to store known relations
        vector<int> arr(n+1,0);
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            
            int a=max(x,y);
            int b=min(x,y);

            x=a;
            y=b;

            arr[x]=max(y,arr[x]);
        }
        
        for(int i=2;i<=n;i++){
            arr[i]=max(arr[i],arr[i-1]);
        }

        // for(int i=0;i<(n+1);i++){
        //     cout<<arr[i]<<" ";
        // }
        // cout<<"\n";
    
        int ans = 0;
        for (int right = 1; right <= n; right++)
        {
            ans+=(right-arr[right]);   
        }

        cout << ans << "\n";
    }

    return 0;
}
