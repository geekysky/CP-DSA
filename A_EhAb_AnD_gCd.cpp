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
        
        if(n==2){
            cout << 1 << " " << 1 << endl;
            continue;
        }

        else if (n % 2)
        {
            cout << 1 << " " << n - 1 << endl;
            continue;
        }

        cout << 2 << " " << n - 2 << endl;
    }
    return 0;
}