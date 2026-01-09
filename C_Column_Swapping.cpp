#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> arr(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];

        vector<vector<int>> copy = arr;
        vector<map<int, deque<int>>> orders(n);

        for (int i = 0; i < n; i++)
        {
            sort(copy[i].begin(), copy[i].end());
            for (int j = 0; j < m; j++)
            {
                orders[i][copy[i][j]].push_back(j);
            }
        }

        set<int> swaps;
        bool exp = false;

        for (int i = 0; i < n; i++)
        {
            map<int, deque<int>> &row_map = orders[i];
            for (int j = 0; j < m; j++)
            {
                int ele = arr[i][j];
                if (copy[i][j] != arr[i][j])
                {
                    int supposed;
                    for (int k = j + 1; k < m; k++)
                    {
                        if (arr[i][k] == copy[i][j] and copy[i][k] != arr[i][k])
                        {   
                            //dont duisturb which are already good 
                            supposed = k;
                            break;
                        }
                    }

                    swaps.insert(supposed);
                    swaps.insert(j);

                    //cout << j << " " << supposed << endl;
                    if (swaps.size() == 2)
                    {
                        exp = true;
                        for (int k = 0; k < n; k++)
                        {
                            swap(arr[k][*swaps.begin()], arr[k][*swaps.rbegin()]);
                        }
                        break;
                    }
                }
            }
            if (exp)
                break;
        }

        // check if arr is sorted row-wise
        bool pos = true;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != copy[i])
            {
                pos = false;
                break;
            }
        }

        if (!pos)
        {
            cout << -1 << endl;
        }
        else
        {
            if (swaps.empty())
                cout << 1 << " " << 1 << endl;
            else
                cout << *swaps.begin() + 1 << " " << *swaps.rbegin() + 1 << endl;
        }
    }
    return 0;
}
