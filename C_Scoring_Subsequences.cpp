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
        if (n == 1)
        {
            cout << 1 << endl;
            continue;
        }

        vector<int> flt_idx(n + 1, -1);

        for (int i = 0; i < n; i++)
        {
            int right = n - i;
            if (arr[i] < right)
            {
                // arr[i]+1 th element nahi ban sakta arr[i]
                flt_idx[i + arr[i] + 1] = i + 1;
            }
        }
        
        int idx=-1;
        for(int i=1;i<=n;i++){
            if(flt_idx[i]!=-1){
                idx=i;
                break;
            }

            else{
                cout<<i<<" ";
            }
        }
        
        if(idx==-1){
            //all length r 
            continue;
        }

        int ctr=1;
        
        while(idx<=n){
            if(flt_idx[idx]!=-1){
                ctr=flt_idx[idx];
            }
            
            cout<<idx-ctr<<" ";

            idx++;
        }
        cout<<endl;
    }
    return 0;
}