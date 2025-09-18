class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void backtrack(int k, int n, int start) {
        if (path.size() == k && n == 0) {
            res.push_back(path);
            return;
        }
        if (path.size() > k || n < 0) return;
        for (int i = start; i <= 9; i++) {
            path.push_back(i);
            backtrack(k, n - i, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        backtrack(k, n, 1);
        return res;
    }
};
