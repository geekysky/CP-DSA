#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    // fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

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

        sort(arr.begin(), arr.end());
        int ans = arr[0] * arr[n - 1];

        for (int i = 0; i <= n / 2; i++)
        {
            if (arr[i] * arr[n - i - 1] != ans)
            {
                ans = -1;
                break;
            }
        }
        
        multiset<int> ms;
        for(int i=0;i<n;i++){
            ms.insert(arr[i]);
        }

        for(int i=2;i*i<=ans;i++){
            if(ans%i==0){
                if(ms.find(i)==ms.end() || ms.find(ans/i)==ms.end()){
                    ans=-1;
                    break;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}