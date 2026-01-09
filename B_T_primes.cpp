#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{   
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {   
        int ele = arr[i];

        if(ele<=3){
            cout<<"NO"<<'\n';
            continue;
        }

        bool flag = true;
        int x = sqrt(ele);
        if (x * x == ele)
        {
            for (int j = 2; j * j <= x; j++)
            {
                if (x % j == 0)
                {
                    flag = false;
                    break;
                }
            }

            if (flag)
                cout << "YES" << '\n';

            else
                cout << "NO" << "\n";
        }

        else{
            cout<<"NO"<<"\n";
        }
    }
    return 0;
}