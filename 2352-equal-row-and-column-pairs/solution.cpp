class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        map<vector<int>, int> rowCount;

        // عد الصفوف
        for (int i = 0; i < n; i++) {
            rowCount[grid[i]]++;
        }

        int result = 0;
        // شكل الأعمدة
        for (int j = 0; j < n; j++) {
            vector<int> col;
            for (int i = 0; i < n; i++) {
                col.push_back(grid[i][j]);
            }
            if (rowCount.count(col)) {
                result += rowCount[col];
            }
        }

        return result;
    }
};
