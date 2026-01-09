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

        vector<int> arr(n);
        int idx = -1;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] == n)
            {
                idx = i;
            }
        }

        if (n == 1)
        {
            cout << arr[0] << endl;
            return 0;
        }

        if (idx != 0)
        {
            vector<vector<int>> poss;
            int l = idx - 1;
            int r = idx - 1;
            while (l >= 0)
            {
                vector<int> temp;
                for (int i = r; i >= l; i--)
                {
                    temp.push_back(arr[i]);
                }
                for (int i = 0; i < l; i++)
                {
                    temp.push_back(arr[i]);
                }
                poss.push_back(temp);
                l--;
            }
            sort(poss.rbegin(), poss.rend());
            vector<int> opt;
            for (int i = idx; i < n; i++)
            {
                opt.push_back(arr[i]);
            }
            for (auto el : poss[0])
            {
                opt.push_back(el);
            }
            if (idx == n - 1)
            {
                vector<int> opt2;
                opt2.push_back(n);
                for (int i = 0; i < n - 1; i++)
                {
                    opt2.push_back(arr[i]);
                }
                if (opt2 > opt)
                {
                    for (auto el : opt2)
                    {
                        cout << el << " ";
                    }
                    cout << endl;
                    return 0;
                }
            }
            for (auto el : opt)
            {
                cout << el << " ";
            }
            cout << endl;
            return 0;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (arr[i] == n - 1)
                {
                    idx = i;
                    break;
                }
            }

            vector<vector<int>> poss;

            int l = idx - 1;
            int r = idx - 1;
            while (l >= 0)
            {
                vector<int> temp;
                for (int i = r; i >= l; i--)
                {
                    temp.push_back(arr[i]);
                }
                for (int i = 0; i < l; i++)
                {
                    temp.push_back(arr[i]);
                }
                poss.push_back(temp);
                l--;
            }
            sort(poss.rbegin(), poss.rend());
            vector<int> opt;
            for (int i = idx; i < n; i++)
            {
                opt.push_back(arr[i]);
            }
            for (auto el : poss[0])
            {
                opt.push_back(el);
            }
            if (idx == n - 1)
            {
                vector<int> opt2;
                opt2.push_back(n - 1);
                for (int i = 0; i < n - 1; i++)
                {
                    opt2.push_back(arr[i]);
                }
                if (opt2 > opt)
                {
                    for (auto el : opt2)
                    {
                        cout << el << " ";
                    }
                    cout << endl;
                    return 0;
                }
            }
            for (auto el : opt)
            {
                cout << el << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}