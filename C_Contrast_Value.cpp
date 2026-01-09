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
        int c = 0;
        for (int i = 1; i < n; i++)
        {
            c += abs(arr[i] - arr[i - 1]);
        }

        if (c == 0)
        {
            cout << 1 << "\n";
            continue;
        }
        if (c != 0 and n == 2)
        {
            cout << 2 << "\n";
            continue;
        }

        // find number of segments which are increasing and decreasing
        int groups = 1;
        bool inc = false, desc = false;
        vector<int> temp;
        temp.push_back(arr[0]);
        for (int i = 1; i < n; i++)
        {
            if (arr[i] != temp.back())
            {
                temp.push_back(arr[i]);
            }
        }
        n = temp.size();

        if (n == 1)
        {
            cout << 1 << "\n";
            continue;
        }

        if (temp[1] > temp[0])
        {
            inc = true;
        }
        else
        {
            desc = true;
        }

        for (int i = 2; i < n; i++)
        {
            if (temp[i] > temp[i - 1] and desc)
            {
                groups++;
                desc = false;
                inc = true;
            }
            else if (temp[i] < temp[i - 1] and inc)
            {
                groups++;
                inc = false;
                desc = true;
            }
        }

        cout<<groups+1<<"\n";
    }
    return 0;
}