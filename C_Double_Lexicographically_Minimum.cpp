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
        string res(n, 'a');
        int l = 0, r = n - 1;

        sort(s.begin(), s.end());

        int i = 0;
        while (i < n)
        {
            if (i + 1 < n && s[i] == s[i + 1])
            {
                // place one at l and one at r
                res[l++] = s[i];
                res[r--] = s[i];
                i += 2;
            }
            else
            {
                if (i + 1 < n && s[i + 1] == s.back())
                {
                    // same character from i+1 to end
                    int k = n - i - 1;
                    int val = (k + 1) / 2;

                    for (int j = 0; j < val; j++)
                        res[l++] = s[i + 1];

                    res[l++] = s[i]; // place current single char in the middle

                    val = k / 2;
                    for (int j = 0; j < val; j++)
                        res[l++] = s[i + 1];

                }
                else
                {
                    // place s[i+1] at left, s[i] at right
                    res[l++] = s[i + 1];
                    res[r--] = s[i];

                    // place as it is in the res string
                    for (int j = i + 2; j < n; j++)
                    {
                        res[l] = s[j];

                        l++;
                    }
                }

                break;
            }
        }

        string temp = res;
        reverse(temp.begin(), temp.end());

        cout << max(res, temp) << '\n';
    }
    return 0;
}
