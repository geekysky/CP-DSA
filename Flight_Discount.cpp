#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int INF = 1e18;

struct ele
{
	int node_no;
	int d;
	int relaxed;

	bool operator<(const ele &other) const
	{
		// sorted in descending order of d variable, so TOP is pointing to smallest
		return d > other.d;
	}
};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, int>>> graph(n + 1);

	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;

		graph[u].push_back({v, w});
	}

	vector<vector<int>> dist(n + 1, vector<int>(2, INF));
	vector<int> parent(n + 1, 0), visited(n + 1, 0);

	priority_queue<ele> pq;

	dist[1][0] = 0;
	dist[1][1] = 0;
	pq.push({1, 0, 0});
	parent[1] = 0;

	while (!pq.empty())
	{
		auto ele = pq.top();
		pq.pop();

		int node = ele.node_no;
		int dt = ele.d;
		int used = ele.relaxed;

		if (dt > dist[node][used])
			continue;

		for (auto nb : graph[node])
		{
			int neighbor = nb.first;
			int wt = nb.second;

			// edge might or might've not been relaxed yet...
			if (dist[neighbor][used] > dt + wt)
			{
				dist[neighbor][used] = dt + wt;
				pq.push({neighbor, dist[neighbor][used], used});
			}

			// edge not yet relaxed...
			if (used == 0)
			{
				int discounted = wt / 2;
				if (dist[neighbor][1] > dt + discounted)
				{
					dist[neighbor][1] = dt + discounted;
					pq.push({neighbor, dist[neighbor][1], 1});
				}
			}
		}
	}

	cout << min(dist[n][0], dist[n][1]) << endl;
}