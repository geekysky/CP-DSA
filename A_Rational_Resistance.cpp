#include <bits/stdc++.h>
using namespace std;
#define int long long int

void solve(int a, int b)
{
    if (a >= b)
    {
        // mixed fraction
        if (a % b)
        {
            cout << a / b + b << endl;
        }
        else
        {
            cout << a / b << endl;
        }
    }
}
signed main()
{
    int a, b;
    cin >> a >> b;

    if (a >= b)
    {
        // mixed fraction
        solve(a, b);
    }
    else
    {
        // flip a and b
        solve(b, a);
    }
    
    return 0;
}