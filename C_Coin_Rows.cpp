#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int m;
        cin >> m;

        int arr[2][m];
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }

        vector<int> suf_up(m), pref_down(m);
        for (int i = m - 1; i >= 0; i--)
        {
            if (i == m - 1)
            {
                suf_up[i] = arr[0][i];
            }
            else
            {
                suf_up[i] = suf_up[i + 1] + arr[0][i];
            }
        }

        for (int i = 0; i < m; i++)
        {
            if (i == 0)
            {
                pref_down[i] = arr[1][i];
            }
            else
            {
                pref_down[i] = pref_down[i - 1] + arr[1][i];
            }
        }

        // now the logic is across all m paths ALice will sacrifice her score but
        // she wants to make sure that Bob's score goes down as much as possible
        //  So across all m paths the path that gives the min score for Bob is the answer
        // as Alice will definitely choose that path

        int bob = LLONG_MAX;
        for (int paths = 0; paths < m; paths++)
        {
            // supposedly alice goes down from the current path column
            int up = (paths == m - 1 ? 0 : suf_up[paths + 1]);
            int down = (paths == 0 ? 0 : pref_down[paths - 1]);
            ;

            int curr = max(up, down);

            bob = min(bob, curr);
        }

        cout << bob << "\n";
    }
    return 0;
}