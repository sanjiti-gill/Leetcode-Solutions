class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // The center is the node that appears in both first two edges
        if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1])
            return edges[0][0];
        return edges[0][1];
    }
};
