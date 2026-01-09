#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        int arr[3] = {a, b, c};
        int op=5;

        while (op > 0)
        {
            sort(arr, arr + 3);
            arr[0]++;

            op--;
        }

        int ans = arr[0] * arr[1] * arr[2];
        cout << ans << "\n";
    }

    return 0;
}