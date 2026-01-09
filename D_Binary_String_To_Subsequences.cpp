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

        string s;
        cin >> s;

        set<int> zero_back, one_back;
        int val = 1;
        (s[0] == '0') ? zero_back.insert(val) : one_back.insert(val);

        set<int> dist;
        dist.insert(1);
        vector<int> ans;
        ans.push_back(1);
        for (int i = 1; i < n; i++)
        {
            if (s[i] == '0')
            {
                if (one_back.size() == 0)
                {
                    // new subsequence
                    val++;
                    zero_back.insert(val);

                    ans.push_back(val);
                    dist.insert(val);
                }
                else
                {
                    int idx = *one_back.rbegin();
                    one_back.erase(*one_back.rbegin());
                    zero_back.insert(idx);

                    ans.push_back(idx);
                    dist.insert(idx);
                }
            }
            else
            {
                if (zero_back.size() == 0)
                {
                    // new subsequence
                    val++;
                    one_back.insert(val);

                    ans.push_back(val);
                    dist.insert(val);
                }
                else
                {
                    int idx = *zero_back.rbegin();
                    zero_back.erase(*zero_back.rbegin());
                    one_back.insert(idx);

                    ans.push_back(idx);
                    dist.insert(idx);
                }
            }
        }

        cout << dist.size() << endl;
        for (auto x : ans)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}