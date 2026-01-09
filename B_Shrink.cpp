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
        int val = 3;
        arr[0] = 2;
        arr[n - 1] = 1;

        // bich k saare good hai
        int s = 1, e = n - 2;

        while (s <= e)
        {   
            if(s==e){
                arr[s]=val;
                break;
            }
            arr[e] = val;
            arr[s] = val + 1;

            e--;
            s++;

            val += 2;
        }

        for (auto x : arr)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}