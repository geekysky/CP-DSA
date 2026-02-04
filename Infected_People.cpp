#include <bits/stdc++.h>
using namespace std;
#define int long long int

vector<vector<int>> graph, dist, visited;
vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};
using state = pair<int, int>;
int n, m, temp_max;

bool is_valid(int x, int y)
{
    if (x >= 0 and x < n and y >= 0 and y < m and graph[x][y] != 0)
    {
        return true;
    }

    return false;
}

signed main()
{
    cin >> n >> m;

    graph.assign(n, vector<int>(m, -1));
    dist.assign(n, vector<int>(m, 1e9));
    visited.assign(n, vector<int>(m, 0));

    queue<state> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int ele;
            cin >> ele;
            graph[i][j] = ele;

            if (ele == 2)
            {
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }

    while (!q.empty())
    {
        state curr = q.front();
        q.pop();

        int x = curr.first;
        int y = curr.second;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (is_valid(nx, ny) and graph[nx][ny] == 1 and dist[nx][ny] == 1e9)
            {
                dist[nx][ny] = min(dist[nx][ny], dist[x][y] + 1);

                q.push({nx, ny});
            }
        }
    }

    // har component ka max time required for it to completely get infected is now available

    int maximum_min_comp_affected_time=0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((graph[i][j] == 1 or graph[i][j] == 2))
            {
                maximum_min_comp_affected_time = max(maximum_min_comp_affected_time, dist[i][j]);
            }
        }
    }

    if (maximum_min_comp_affected_time == 1e9)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << maximum_min_comp_affected_time << endl;
    }

    return 0;
}