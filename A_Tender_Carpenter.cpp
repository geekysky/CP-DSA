#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
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

        bool found = false;
        for (int i = n - 2; i >= 0; i--)
        {
            if (2 * min(arr[i],arr[i+1]) > max(arr[i + 1],arr[i]))
            {
                found = true;
                break;
            }
        }

        if (found)
            cout << "YES" << "\n";

        else
            cout << "NO" << "\n";
    }
    return 0;
}