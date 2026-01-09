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
        vector<int> lengths;
        int val = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                lengths.push_back(val);
                val = 0;
            }
            else
            {
                val++;
            }
        }

        if (val != 0)
        {
            lengths.push_back(val);
        }

        sort(lengths.rbegin(), lengths.rend());
        val = 0;

        for (int i = 0; i < lengths.size(); i += 2)
        {
            val += lengths[i];
        }

        cout << val << endl;
    }
    return 0;
}