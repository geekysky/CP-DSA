#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int test_cases;
    cin >> test_cases;

    while (test_cases--)
    {
        string s, t;
        cin >> s >> t;

        int s_len = s.length();
        int t_len = t.length();

        int i = 0, j = 0;

        while (i < s_len && j < t_len)
        {
            if (s[i] == t[j] || s[i] == '?')
            {
                if (s[i] == '?')
                {
                    s[i] = t[j];
                }
                j++;
            }
            i++;
        }

        if (j == t_len)
        {
            cout << "YES" << "\n";
            for (int k = 0; k < s_len; k++)
            {
                if (s[k] == '?')
                {
                    s[k] = 'a';
                }
            }
            cout << s << "\n";
        }
        else
        {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
