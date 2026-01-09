#include <bits/stdc++.h>
using namespace std;
#define int long long int 

class SparseTable
{
    vector<vector<int>> st;
    vector<vector<int>> st_max;
    int n;

public:
    SparseTable(vector<int> &arr)
    {
        n = arr.size();
        int k = log2(n) + 1;
        st.resize(n, vector<int>(k));
        st_max.resize(n, vector<int>(k));

        for (int i = 0; i < n; i++)
        {
            st[i][0] = st_max[i][0] = arr[i];
        }

        for (int j = 1; j < k; j++)
        {
            for (int i = 0; i + (1 << j) <= n; i++)
            {
                st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
                st_max[i][j] = max(st_max[i][j - 1], st_max[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int query_min(int L, int R)
    {
        int j = log2(R - L + 1);
        return min(st[L][j], st[R - (1 << j) + 1][j]);
    }

    int query_max(int L, int R)
    {
        int j = log2(R - L + 1);
        return max(st_max[L][j], st_max[R - (1 << j) + 1][j]);
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    while (q >= 0)
    {
        SparseTable st(arr);
        int max_convenience = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                int curr = st.query_max(i, j) - st.query_min(i, j) - (j - i);
                max_convenience = max(max_convenience, curr);
            }
        }

        cout << max_convenience << "\n";

        if (q == 0)
            break;

        int p, x;
        cin >> p >> x;
        arr[p - 1] = x;
        q--;
    }
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}