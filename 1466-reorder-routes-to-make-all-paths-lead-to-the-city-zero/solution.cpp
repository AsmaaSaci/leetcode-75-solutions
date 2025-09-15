#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adj(n); 
        // pair: (nextNode, flag) -> flag=0 إذا الحافة تخرج من العقد الحالي (لازم تتغير)
        // flag=1 إذا الحافة داخلة (جاهزة)
        
        for (auto &c : connections) {
            int a = c[0], b = c[1];
            adj[a].push_back({b, 0}); // a -> b (قد نحتاج نعكسها)
            adj[b].push_back({a, 1}); // b -> a (جاهزة)
        }
        
        vector<bool> visited(n, false);
        int changes = 0;
        
        function<void(int)> dfs = [&](int node) {
            visited[node] = true;
            for (auto [next, flag] : adj[node]) {
                if (!visited[next]) {
                    if (flag == 0) changes++; // لازم نغير اتجاهها
                    dfs(next);
                }
            }
        };
        
        dfs(0);
        return changes;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> c1 = {{0,1},{1,3},{2,3},{4,0},{4,5}};
    cout << sol.minReorder(6, c1) << endl; // 3

    vector<vector<int>> c2 = {{1,0},{1,2},{3,2},{3,4}};
    cout << sol.minReorder(5, c2) << endl; // 2

    vector<vector<int>> c3 = {{1,0},{2,0}};
    cout << sol.minReorder(3, c3) << endl; // 0
}
