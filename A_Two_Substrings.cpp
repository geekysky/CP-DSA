#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    string s;
    cin >> s;

    bool ab = false, ba = false;
    int i=0;

    while(i<s.size()-1)
    {
        if (s[i] == 'A' and s[i + 1] == 'B' and !ab)
        {
            ab = true;
            i += 2;
        }
        else if (s[i] == 'B' and s[i + 1] == 'A' and !ba)
        {
            ba = true;
            i += 2;
        }
        else{
            i++;
        }
    }

    if (ab and ba)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}