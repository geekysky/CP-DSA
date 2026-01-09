#include <bits/stdc++.h>
using namespace std;
#define ll long long

int query(int index)
{
    // returns the ele at the i/p index
    cout << "? " << index << endl;
    int ele;
    cin >> ele;

    return ele;
}

int main()
{
    int n;
    cin >> n;

    int left = 1, right = n;
    int ans = right + 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;

        // now check if mid is valid local minima or not
        // a b c
        int a = (mid == 1 ? 1e9 : query(mid - 1));
        int b = query(mid);
        int c = (mid == n  ? 1e9 : query(mid + 1));

        if (a > b and c > b)
        {
            ans = mid;
            break;
        }
        else if (a < b)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    cout << "! " << ans << endl;

    return 0;
}