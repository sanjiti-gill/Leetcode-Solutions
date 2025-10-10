#include <vector>
using namespace std;
class UnionFind {
    vector<int> parent;
public:
    UnionFind(int n) : parent(n) {
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if(parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if(px != py) parent[py] = px;
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        UnionFind uf(n);
        for(int i = 0; i < n-1; i++) {
            if(nums[i+1] - nums[i] <= maxDiff)
                uf.unite(i, i+1);
        }
        vector<bool> ans;
        for(auto &q : queries) {
            ans.push_back(uf.connected(q[0], q[1]));
        }
        return ans;
    }
};