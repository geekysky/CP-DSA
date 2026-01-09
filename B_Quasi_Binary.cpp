#include <bits/stdc++.h>
using namespace std;
string s;
int n = 0, a[7];
int main()
{
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        n = max(n, s[i] - '0');
        a[i] = s[i] - '0';
    }
    cout << n << endl;
    while (n-- > 0)
    {
        int g = 1;
        for (int i = 0; i < s.size(); i++)
        {
            if (a[i] > 0)
                cout << 1, g = 0;
            else if (!g)
                cout << 0;
            a[i]--;
        }
        cout << " ";
    }
    return 0;
}