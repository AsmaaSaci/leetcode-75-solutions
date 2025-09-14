#include <unordered_map>
using namespace std;

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
    int dfs(TreeNode* node, long currSum, int targetSum, unordered_map<long, int>& prefixCount) {
        if (!node) return 0;

        currSum += node->val;
        int count = 0;

        // If there exists a prefix sum such that currSum - prefixSum = targetSum
        if (prefixCount.count(currSum - targetSum)) {
            count += prefixCount[currSum - targetSum];
        }

        // Add current sum to map
        prefixCount[currSum]++;

        // Recurse into children
        count += dfs(node->left, currSum, targetSum, prefixCount);
        count += dfs(node->right, currSum, targetSum, prefixCount);

        // Backtrack
        prefixCount[currSum]--;

        return count;
    }

    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long, int> prefixCount;
        prefixCount[0] = 1;  // Base case: one path with sum = 0
        return dfs(root, 0, targetSum, prefixCount);
    }
};
