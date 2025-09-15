#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        queue<pair<int,int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+'; // mark visited

        int steps = 0;
        vector<int> dir = {0,1,0,-1,0};

        while (!q.empty()) {
            int sz = q.size();
            steps++;
            for (int i = 0; i < sz; i++) {
                auto [r, c] = q.front(); q.pop();

                for (int d = 0; d < 4; d++) {
                    int nr = r + dir[d], nc = c + dir[d+1];
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                    if (maze[nr][nc] == '.') {
                        if (nr == 0 || nr == m-1 || nc == 0 || nc == n-1) 
                            return steps;
                        maze[nr][nc] = '+';
                        q.push({nr, nc});
                    }
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;

    vector<vector<char>> maze1 = {{'+','+','.','+'},{'.','.','.','+'},{'+','+','+','.'}};
    vector<int> entrance1 = {1,2};
    cout << sol.nearestExit(maze1, entrance1) << endl; // 1

    vector<vector<char>> maze2 = {{'+','+','+'},{'.','.','.'},{'+','+','+'}};
    vector<int> entrance2 = {1,0};
    cout << sol.nearestExit(maze2, entrance2) << endl; // 2

    vector<vector<char>> maze3 = {{'.','+'}};
    vector<int> entrance3 = {0,0};
    cout << sol.nearestExit(maze3, entrance3) << endl; // -1
}
