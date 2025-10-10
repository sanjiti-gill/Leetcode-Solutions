#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int minCycle = n + 1;

        for (int start = 0; start < n; ++start) {
            vector<int> dist(n, -1);
            vector<int> parent(n, -1);
            queue<int> q;
            dist[start] = 0;
            q.push(start);

            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : adj[u]) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        parent[v] = u;
                        q.push(v);
                    } else if (v != parent[u]) {
                        minCycle = min(minCycle, dist[u] + dist[v] + 1);
                    }
                }
            }
        }

        return (minCycle == n + 1) ? -1 : minCycle;
    }
};