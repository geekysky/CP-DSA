#include <bits/stdc++.h>
using namespace std;
#define int long long int
vector<vector<char>> graph, cpy;
vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};
int n, m, k, req, visits = 0;

bool is_valid(int x, int y)
{
    if (x >= 0 and x < n and y >= 0 and y < m)
        return true;

    return false;
}

void dfs(int x, int y)
{
    cpy[x][y] = 'z';
    visits++;

    if (visits == req)
        return;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (is_valid(nx, ny) and cpy[nx][ny] == '.')
        {
            dfs(nx, ny);

            if (req == visits)
                return;
        }
    }
}

signed main()
{
    cin >> n >> m >> k;
    graph.assign(n, vector<char>(m, '-'));

    int empty = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char ch;
            cin >> ch;

            graph[i][j] = ch;

            if (graph[i][j] == '.')
            {
                empty++;
            }
        }
    }

    cpy = graph;
    req = empty - k;

    // cout<<empty<<" "<<req<<endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visits < req and cpy[i][j] == '.')
            {
                dfs(i, j);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (cpy[i][j] == 'z')
            {
                cpy[i][j] = '.';
            }
            else if (cpy[i][j] == '.')
            {
                // turn into wall
                cpy[i][j] = 'X';
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << cpy[i][j];
        }
        cout << endl;
    }

    return 0;
}