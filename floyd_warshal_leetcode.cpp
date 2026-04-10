class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {   
        vector<vector<int>> graph;

        graph.assign(n + 1, vector<int>(n, 1e18));

        for (int i = 0; i < n; i++)
        {
            graph[i][i] = 0;
        }

        for (auto edge:edges)
        {   

            int u, v, w;
            u = edge[0];
            v = edge[1];
            w = edge[2];

            graph[u][v] = min(graph[u][v], w);
            graph[v][u] = min(graph[v][u], w);
        }

        // all pair shortest path
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }

        int node=-1;
        int min_cities = __INT_MAX__;

        for(int i=0;i<n;i++){
            int cities = 0;
            for(int j=0;j<n;j++){
                if(i!=j){
                    if(graph[i][j] <= distanceThreshold){
                        cities++;
                    }
                }
            }

            if(cities <= min_cities){
                node = i;

                min_cities = cities;
            }
            
            return node;


        }


    }
};