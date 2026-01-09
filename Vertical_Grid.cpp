#include <bits/stdc++.h>
using namespace std;
#define int long long int

vector<vector<int>> grid;
vector<vector<int>> visited;
vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};

int n, k, comp_sz;

bool valid_neighbor(int x, int y)
{
    if (x >= 0 and x < n and y >= 0 and y < 10)
    {
        if (visited[x][y] != -1)
        {
            return true;
        }
    }

    return false;
}

void dfs(int row, int col)
{
    comp_sz++;
    visited[row][col] = -1;

    for (int i = 0; i < 4; i++)
    {
        int x = row + dx[i];
        int y = col + dy[i];

        if (valid_neighbor(x, y))
        {
            if (grid[row][col] == grid[x][y])
            {
                // same color neighbor
                dfs(x, y);
            }
        }
    }
}

signed main()
{
    cin >> n >> k;

    grid.resize(n, vector<int>(10, 0));
    visited.resize(n, vector<int>(10, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            int ele;
            cin >> ele;

            grid[i][j] = ele;
            visited[i][j] = ele;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (grid[i][j])
            {
                // non zero cell
                int col = grid[i][j];
                comp_sz = 0;

                // DEBUGGING GRID
                for (int p = 0; p < n; p++)
                {
                    for (int q = 0; q < 10; q++)
                    {
                        cout<<grid[p][q];
                    }
                    cout<<endl;
                }
                cout<<endl;

                dfs(i, j);

                if (comp_sz < k)
                {
                    // useless component
                    // remark it back to original color col
                    for (int p = 0; p < n; p++)
                    {
                        for (int q = 0; q < 10; q++)
                        {
                            if (visited[p][q] == -1)
                            {
                                visited[p][q] = col;
                            }
                        }
                    }
                }
                else
                {
                    for (int q = 0; q < 10; q++)
                    {
                        int z = 0;
                        vector<int> refer;
                        for (int p = 0; p < n; p++)
                        {
                            if (visited[p][q] == -1)
                            {
                                visited[p][q] = 0;
                                z++;
                            }
                            else
                            {
                                refer.push_back(visited[i][j]);
                            }
                        }

                        for (int i = 1; i <= z; i++)
                        {
                            refer.push_back(0);
                        }

                        reverse(refer.begin(), refer.end());
                        for (int i = 0; i < n; i++)
                        {
                            grid[i][j] = refer[i];
                            visited[i][j] = refer[i];
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}