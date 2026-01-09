#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    int ones = 0;
    vector<int> pos;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];

        if (arr[i] == 1)
        {
            ones++;
            pos.push_back(i);
        }
    }

    if (ones == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    else if (ones == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    //now find distance between ones 
    int ans=1;

    for(int i=1;i<pos.size();i++){
        ans=ans*(pos[i]-pos[i-1]);
    }

    cout<<ans<<endl;
    return 0;
}