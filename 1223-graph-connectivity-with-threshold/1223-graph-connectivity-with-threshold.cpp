#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        vector<int> parent(n+1), rank(n+1, 0);
        for (int i = 1; i <= n; i++) parent[i] = i;
        for (int d = threshold + 1; d <= n; d++) {
            for (int multiple = 2*d; multiple <= n; multiple += d) {
                unite(parent, rank, d, multiple);
            }
        }
        vector<bool> ans;
        for (auto &q : queries) {
            int a = q[0], b = q[1];
            ans.push_back(find(parent, a) == find(parent, b));
        }
        return ans;
    }
private:
    int find(vector<int>& parent, int x) {
        if (parent[x] != x) parent[x] = find(parent, parent[x]);
        return parent[x];
    }
    void unite(vector<int>& parent, vector<int>& rank, int x, int y) {
        int px = find(parent, x), py = find(parent, y);
        if (px == py) return;
        if (rank[px] < rank[py]) parent[px] = py;
        else if (rank[px] > rank[py]) parent[py] = px;
        else {
            parent[py] = px;
            rank[px]++;
        }
    }
};