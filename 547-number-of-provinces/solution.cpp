#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int city, vector<vector<int>>& isConnected, vector<bool>& visited) {
        visited[city] = true;
        for (int i = 0; i < isConnected.size(); i++) {
            if (isConnected[city][i] == 1 && !visited[i]) {
                dfs(i, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int provinces = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                provinces++;
                dfs(i, isConnected, visited);
            }
        }

        return provinces;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> isConnected1 = {{1,1,0},{1,1,0},{0,0,1}};
    cout << sol.findCircleNum(isConnected1) << endl; // Output: 2

    vector<vector<int>> isConnected2 = {{1,0,0},{0,1,0},{0,0,1}};
    cout << sol.findCircleNum(isConnected2) << endl; // Output: 3

    return 0;
}
