#include <bits/stdc++.h>
using namespace std;
#define int long long int
using state = pair<int, int>;
vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};
vector<vector<char>> graph;
int n, m;

bool is_valid(int x, int y, int n, int m)
{
    if (x >= 0 and x < n and y >= 0 and y < m)
    {
        if (graph[x][y] != '#')
        {
            return true;
        }
    }

    return false;
}

signed main()
{

    cin >> n >> m;

    graph.assign(n, vector<char>(m, 'Z'));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char ele;
            cin >> ele;

            graph[i][j] = ele;
        }
    }

    bool pos = true;
    vector<vector<int>> dist(n, vector<int>(m, 1e9));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (graph[i][j] == 'M')
            {
                // for all reachable boundaries calculate the min distance required
                dist.assign(n, vector<int>(m, 1e9));

                queue<state> q;
                dist[i][j] = 0;
                q.push(make_pair(i, j));

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

                        if (is_valid(nx, ny, n, m))
                        {
                            if (dist[nx][ny] == 1e9)
                            {
                                // unvisited node
                                dist[nx][ny] = dist[x][y] + 1;
                                q.push(make_pair(nx, ny));
                            }
                        }
                    }
                }

                
            }
        }
    }

    return 0;
}