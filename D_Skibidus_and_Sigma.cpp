#include <bits/stdc++.h>
using namespace std;
#define int long long int

void solve_test_case()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> arrays(n, vector<int>(m));
    vector<pair<int, int>> row_sums;

    for (int i = 0; i < n; i++)
    {
        int row_sum = 0;
        for (int j = 0; j < m; j++)
        {
            cin >> arrays[i][j];
            row_sum += arrays[i][j];
        }
        row_sums.push_back({-row_sum, i});
    }

    sort(row_sums.begin(), row_sums.end());

    vector<int> final_array;
    final_array.reserve(n * m);

    for (const auto &p : row_sums)
    {
        int row_idx = p.second;
        final_array.insert(final_array.end(),
                           arrays[row_idx].begin(),
                           arrays[row_idx].end());
    }

    int result = 0;
    int weight = n * m;

    for (int num : final_array)
    {
        result += num * weight--;
    }

    cout << result << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_cases;
    cin >> test_cases;

    while (test_cases--)
    {
        solve_test_case();
    }

    return 0;
}