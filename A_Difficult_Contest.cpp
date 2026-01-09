#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        int n = s.size();

        if (n <= 2)
        {
            cout << s << endl;
            continue;
        }

        // for (int i = 0; i <= n - 3; i++)
        // {
        //     string curr = "";
        //     curr += s[i];
        //     curr += s[i + 1];
        //     curr += s[i + 2];

        //     if (curr == "FFT")
        //     {
        //         s[i + 1] = 'T';
        //         s[i + 2] = 'F';
        //     }
        //     else if (curr == "NTT")
        //     {
        //         s[i] = 'T';
        //         s[i + 1] = 'N';
        //         s[i + 1] = 'T';
        //     }
        // }

        // cout << s << endl;
        sort(s.begin(),s.end());
        reverse(s.begin(),s.end());

        cout<<s<<endl;
    }
    return 0;
}