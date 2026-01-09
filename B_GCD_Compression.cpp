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

        vector<int> arr(2 * n);
        int o = 0, e = 0;
        vector<int> odd, even;
        for (int i = 0; i < 2 * n; i++)
        {
            cin >> arr[i];
            if (arr[i] % 2 == 0)
            {
                e++;
                even.push_back(i + 1);
            }
            else
            {
                o++;
                odd.push_back(i + 1);
            }
        }

        if (o % 2 == 0 and e % 2 == 0)
        {
            if (o > 0)
            {
                odd.pop_back();
                odd.pop_back();
            }
            else
            {
                even.pop_back();
                even.pop_back();
            }
        }
        else if (o % 2 != 0 and e % 2 != 0)
        {
            odd.pop_back();
            even.pop_back();
        }

        // at this stage both odd and even have even number of elements
        for (int i = 0; i < (n - 1); i++)
        {
            if (odd.size())
            {
                cout << odd.back() << " ";
                odd.pop_back();
                cout << odd.back() << endl;
                odd.pop_back();
            }
            else
            {
                cout << even.back() << " ";
                even.pop_back();
                cout << even.back() << endl;
                even.pop_back();
            }
        }
        // cout << "\n";
    }
    return 0;
}