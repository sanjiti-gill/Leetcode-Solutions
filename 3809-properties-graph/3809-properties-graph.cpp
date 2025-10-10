#include <vector>
#include <set>
#include <functional>
using namespace std;

class Solution {
public:
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n = properties.size();
        vector<vector<int>> graph(n);
        vector<set<int>> distinctProps(n);
        for (int i = 0; i < n; i++)
            distinctProps[i] = set<int>(properties[i].begin(), properties[i].end());
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int cnt = 0;
                for (int x : distinctProps[i])
                    if (distinctProps[j].count(x)) cnt++;
                if (cnt >= k) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        vector<bool> visited(n, false);
        int components = 0;

        function<void(int)> dfs = [&](int u) {
            visited[u] = true;
            for (int v : graph[u])
                if (!visited[v])
                    dfs(v);
        };

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i);
                components++;
            }
        }

        return components;
    }
};