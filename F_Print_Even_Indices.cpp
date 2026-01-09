#include <bits/stdc++.h>
using namespace std;
#define int long long int

void print(int idx, vector<int> &arr, int n)
{
    if (idx < 0)
        return;
    
    if(idx%2==0)
    cout << arr[idx] << " ";


    print(idx-1, arr, n);
}

signed main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    print(n-1, arr, n);
    return 0;
}