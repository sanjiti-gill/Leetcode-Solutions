#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int res = INT_MIN;
        for (int i = 0; i < n; i++) {
            vector<int> neighbors;
            for (int nei : adj[i]) {
                if (vals[nei] > 0) neighbors.push_back(vals[nei]);
            }
            sort(neighbors.rbegin(), neighbors.rend());
            int sum = vals[i];
            for (int j = 0; j < min(k, (int)neighbors.size()); j++) {
                sum += neighbors[j];
            }
            res = max(res, sum);
        }
        return res;
    }
};