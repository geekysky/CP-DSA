#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, w;
        cin >> n >> w;

        vector<int> arr(n);
        int area = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];

            area += arr[i];
        }
        if (n == 1)
        {
            cout << 1 << endl;
            continue;
        }

        sort(arr.begin(), arr.end());
        int s = 0, e = n - 1;
        int height = 0, temp = 0;
        while (s <= e)
        {
            temp += arr[s];

            if (temp + arr[e] > w)
            {
                // picking this value from s has caused overflow
                height++;
                temp = arr[s];
                e--;
            }

            else
            {
                s++;
            }
        }

        cout<<height<<endl;
    }
    return 0;
}