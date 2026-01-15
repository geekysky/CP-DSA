#include <bits/stdc++.h>
using namespace std;
#define int long long int

vector<vector<pair<int, int>>> g;
vector<int> dis;
int nodes, n, m;
vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};

void BFS01(int sc)
{
    for (int i = 1; i <= nodes; i++)
        dis[i] = 1e18;

    deque<int> dq;
    dis[sc] = 0;
    dq.push_back(sc);

    while (!dq.empty())
    {
        int node = dq.front();
        dq.pop_front();

        for (auto v : g[node])
        {
            int neigh = v.first;
            int wt = v.second;

            if (dis[neigh] > dis[node] + wt)
            {
                dis[neigh] = dis[node] + wt;
                if (wt == 0)
                    dq.push_front(neigh);
                else
                    dq.push_back(neigh);
            }
        }
    }
}

int find_node_number(int row, int col, int n, int m)
{
    int ans;

    ans = (row * m) + (col + 1);

    return ans;
}

bool is_valid(int row, int col)
{
    if (row >= 0 and row < n and col >= 0 and col < m)
    {
        return true;
    }

    return false;
}

signed main()
{

    cin >> n >> m;

    vector<vector<int>> arr;
    arr.assign(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int ele;
            cin >> ele;

            arr[i][j] = ele;
        }
    }

    nodes = n * m;
    g.resize(nodes + 1);
    dis.assign(nodes + 1, 1e18);

    // 2d array to proper graph building
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int node_number = find_node_number(i, j, n, m);

            // har ek node k max 3 neighbor honge with edge weights 0/1
            int direction = arr[i][j];

            int nb_row = i;
            int nb_col = j;

            if (direction == 1)
            {
                nb_col++;
            }
            else if (direction == 2)
            {
                nb_col--;
            }
            else if (direction == 3)
            {
                nb_row++;
            }
            else
            {
                nb_row--;
            }

            for (int k = 0; k < 4; k++)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if (is_valid(nx, ny))
                {
                    // i,j (node_no) -> nx,ny (node_no)
                    int edge_wt = 1;

                    if (nx == nb_row and ny == nb_col)
                    {
                        edge_wt = 0;
                    }

                    g[node_number].push_back(make_pair(find_node_number(nx, ny, n, m), edge_wt));
                }
            }
        }
    }

    BFS01(1);

    cout << dis[n * m] << endl;

    return 0;
}