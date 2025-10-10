#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> state(n, 0); 
        int maxCycle = -1;

        for (int i = 0; i < n; i++) {
            if (state[i] != 0) continue;

            int curr = i, step = 0;
            unordered_map<int,int> nodeToStep;

            while (curr != -1) {
                if (state[curr] == 2) break;     
                if (state[curr] == 1) {          
                    maxCycle = max(maxCycle, step - nodeToStep[curr]);
                    break;
                }

                state[curr] = 1;                
                nodeToStep[curr] = step++;
                curr = edges[curr];
            }

           
            for (auto &[node, _] : nodeToStep) state[node] = 2;
        }

        return maxCycle;
    }
};
