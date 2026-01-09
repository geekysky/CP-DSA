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

        int val = LLONG_MAX;
        int cnt = 0;
        string temp = s;

        while (val)
        {
            string fst = "";
            int v = 0;
            int i = 0;
            while (i < temp.size())
            {
                if (i < temp.size() - 1)
                {
                    if (temp[i] != temp[i + 1] and !v)
                    {
                        v++;
                        i += 2;

                        continue;
                    }
                }

                fst += temp[i];
                i++;
            }

            val = v;
            temp = fst;

            cnt += v;
            //cout << val << " " << temp << " " << fst << " " << cnt << endl;
        }

        //cout << cnt << endl;
        if (cnt % 2)
        {
            cout << "DA" << endl;
        }
        else
        {
            cout << "NET" << endl;
        }
    }
    return 0;
}