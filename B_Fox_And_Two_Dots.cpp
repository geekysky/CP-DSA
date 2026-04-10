#include <bits/stdc++.h>
using namespace std;
#define int long long int
using state = pair<int, int>;
vector<vector<int>> col;
vector<vector<char>> arr;
vector<vector<state>> parent;
vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};
int n, m;

int ans = -1;

bool is_valid(int row, int col, char ch)
{
    if (row >= 0 and row < n and col >= 0 and col < m)
    {
        if (ch == arr[row][col])
        {
            // same character value
            return true;
        }
    }

    return false;
}

void dfs(int x, int y, int px, int py)
{
    parent[x][y] = make_pair(px, py);
    col[x][y] = 2;

    for (int k = 0; k < 4; k++)
    {
        int nx = x + dx[k];
        int ny = y + dy[k];

        if (is_valid(nx, ny, arr[x][y]))
        {
            if (col[nx][ny] == 1)
            {
                // new unvisited node
                // forward edge
                dfs(nx, ny, x, y);

                if (ans == 1e5)
                {
                    return;
                }
            }
            else if (col[nx][ny] == 2 and !(nx == px and ny == py))
            {
                // 2 -> 2
                // back edge detcted

                // the cycle is of length >= 4
                ans = 1e5;
                break;
            }
        }
    }

    if (ans == 1e5)
    {
        return;
    }

    col[x][y] = 3;
}

signed main()
{

    cin >> n >> m;

    col.assign(n, vector<int>(m, 1));

    arr.assign(n, vector<char>(m, 'A'));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    parent.assign(n, vector<state>(m, {-1, -1}));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (col[i][j] == 1)
            {
                // unvisited
                dfs(i, j, -1, -1);
            }
        }
    }

    if (ans >= 4)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}