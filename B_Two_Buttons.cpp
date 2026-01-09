#include <bits/stdc++.h>
using namespace std;
#define int long long

map<int, int> dist;

int n, m;

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    int LIMIT = 2 * max(n, m) + 5;

    while (!q.empty())
    {
        int ele = q.front();
        q.pop();

        if (ele == m) return;

        int n1 = 2 * ele;
        int n2 = ele - 1;

        if (n1 >= 0 && n1 <= LIMIT && !dist.count(n1))
        {
            dist[n1] = dist[ele] + 1;
            q.push(n1);
        }

        if (n2 >= 0 && n2 <= LIMIT && !dist.count(n2))
        {
            dist[n2] = dist[ele] + 1;
            q.push(n2);
        }
    }
}

signed main()
{
    cin >> n >> m;
    bfs(n);
    cout << dist[m] << endl;
}
