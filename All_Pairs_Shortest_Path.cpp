#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int n;
    cin >> n;

    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 1e18));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int ele;
            cin >> ele;
            graph[i][j] = ele;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        graph[i][i] = 0;
    }

    vector<int> popping_order, ans;
    vector<int> is_present(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        int ele;
        cin >> ele;

        popping_order.push_back(ele);
    }

    // nikalna is same as reverse daalna

    for (int i = n - 1; i >= 0; i--)
    {
        int unlock = popping_order[i];

        is_present[unlock] = 1;
        int sum = 0;

        for (int i = 1; i <= n; i++)
        {
            if (is_present[i])
            {
                for (int j = 1; j <= n; j++)
                {
                    if (is_present[j])
                    {
                        graph[i][j] = min(graph[i][j], graph[i][unlock] + graph[unlock][j]);
                    }
                }
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (is_present[i] and is_present[j])
                {
                    // both nodes to be unlocked is bare minimum
                    sum += graph[i][j];
                }
            }
        }

        ans.push_back(sum);
    }

    reverse(ans.begin(),ans.end());
    
    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}