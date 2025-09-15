#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) q.push({i,j});
                else if (grid[i][j] == 1) fresh++;
            }
        }

        if (fresh == 0) return 0;

        int minutes = -1;
        vector<int> dir = {0,1,0,-1,0};

        while (!q.empty()) {
            int sz = q.size();
            minutes++;
            for (int k = 0; k < sz; k++) {
                auto [r, c] = q.front(); q.pop();
                for (int d = 0; d < 4; d++) {
                    int nr = r + dir[d], nc = c + dir[d+1];
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                    if (grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        fresh--;
                        q.push({nr,nc});
                    }
                }
            }
        }

        return fresh == 0 ? minutes : -1;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> g1 = {{2,1,1},{1,1,0},{0,1,1}};
    cout << sol.orangesRotting(g1) << endl; // 4

    vector<vector<int>> g2 = {{2,1,1},{0,1,1},{1,0,1}};
    cout << sol.orangesRotting(g2) << endl; // -1

    vector<vector<int>> g3 = {{0,2}};
    cout << sol.orangesRotting(g3) << endl; // 0
}
