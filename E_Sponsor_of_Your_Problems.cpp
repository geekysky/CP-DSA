#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        string l, r;
        cin >> l >> r;

        int first_diff = -1;
        if (l == r)
        {
            cout << 2 * l.size() << "\n";
            continue;
        }
        else if (stoi(l) == stoi(r) - 1)
        {
            int v = 0;
            for (int i = 0; i < l.size(); i++)
            {
                if (l[i] == r[i])
                {
                    v++;
                }
            }

            cout << l.size() + v << "\n";
            continue;
        }

        bool found = false;
        int rem_l, rem_r;
        int ans = 0;
        for (int i = 0; i < l.size(); i++)
        {
            if (r[i] > l[i])
            {
                if (r[i] - l[i] >= 2)
                {
                    // bich m ek digit hai
                    // common prefix
                    found = true;
                }
                else
                {
                    // 1.... & 2....
                    first_diff = i;
                    rem_l = stoi(l.substr(i , l.size() - i));
                    rem_r = stoi(r.substr(i , l.size() - i));
                }

                break;
            }
            else
            {
                ans += 2;
            }
        }

        if (found)
        {
            cout << ans << endl;
            continue;
        }
        
        // cout<<rem_l<<" "<<rem_r<<endl;

        string bk_pt = "";
        bk_pt += (to_string(rem_r)[0]);

        for (int i = 1; i < to_string(rem_r).size(); i++)
        {
            bk_pt += '0';
        }

        int left = 0, right = 0;
        int num = stoi(bk_pt);

        left = num - rem_l;
        right = rem_r - num + 1;
        
        // cout<<bk_pt<<" "<<left<<" "<<right<<endl;

        int x = 0, y = 0;
        if (left <= 10)
        {
            x = 1;
        }

        int temp = 10;
        for (int i = 1; i <= 8; i++)
        {
            if (left >= temp+1)
            {
                x = i + 1;
            }
            else
            {
                break;
            }

            temp *= 10;
        }

        if (right <= 10)
        {
            y = 1;
        }
        temp = 10;
        for (int i = 1; i <= 8; i++)
        {
            if (right >= temp+1)
            {
                y = i + 1;
            }
            else
            {
                break;
            }

            temp *= 10;
        }
        // cout<<x<<" "<<y<<endl;

        if (left <= right)
        {
            cout << ans + (to_string(rem_r).size() - y) << endl;
        }
        else
        {
            cout << ans + (to_string(rem_r).size() - x) << endl;
        }
        // cout<<endl;
    }

    return 0;
}
