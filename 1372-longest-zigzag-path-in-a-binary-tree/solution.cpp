/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLen = 0;

    void dfs(TreeNode* node, bool cameFromLeft, int length) {
        if (!node) return;
        maxLen = max(maxLen, length);

        if (cameFromLeft) {
            // Last move was left → must go right now
            dfs(node->right, false, length + 1);
            dfs(node->left, true, 1); // restart if we go left again
        } else {
            // Last move was right → must go left now
            dfs(node->left, true, length + 1);
            dfs(node->right, false, 1); // restart if we go right again
        }
    }

    int longestZigZag(TreeNode* root) {
        if (!root) return 0;
        dfs(root->left, true, 1);   // start by going left
        dfs(root->right, false, 1); // start by going right
        return maxLen;
    }
};
