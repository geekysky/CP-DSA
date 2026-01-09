#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        /* code */
        int q;
        cin >> q;
        

        int min_ele_from_all=INT_MAX;
        int second_sum=0;
        int min_second=INT_MAX;
        while (q--)
        {
            int m;
            cin>>m;

            int arr[m];
            for (int i = 0; i < m; i++)
            {
                cin >> arr[i];
            }

            sort(arr, arr + m);

            if(arr[0]<min_ele_from_all){
                min_ele_from_all=arr[0];
            }

            if(arr[1]<min_second){
                min_second=arr[1];
            }

            second_sum+=arr[1];
        }

        cout<<(min_ele_from_all+second_sum)-min_second<<"\n";
    }

    return 0;
}