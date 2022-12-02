class Solution {
public:
     int dijkstra(vector<pair<int, int>> adj[], int n) {
		int mod = 1e9 + 7;
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        vector<long long> dis(n, 1e15), path(n, 0);
        pq.push({0, 0});
        dis[0] = 0;
        path[0] = 1;

        while (!pq.empty()) {
            long long dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto &child : adj[node]) {
                int adjNode = child.first;
                long long wt = child.second;

                if (dist + wt < dis[adjNode]) {
                    dis[adjNode] = dist + wt;
                    path[adjNode] = path[node];
                    pq.push({dist + wt, adjNode});
                }
                else if (dist + wt == dis[adjNode]) {
                    path[adjNode] = (path[node] + path[adjNode]) % mod;
                }
            }
        }

        return path[n - 1];
    }
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> adj[n];

        // create the graph
        for (auto &v : roads) {
            adj[v[0]].push_back({v[1], v[2]});
            adj[v[1]].push_back({v[0], v[2]});
        }
        
        return dijkstra(adj, n);
    }
};