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
    // bool dfs(TreeNode* ver, int k){
    //     if (!ver) return k == 0;
    //     return dfs(ver->left, k-ver->val) || dfs(ver->right, k-ver->val);
    // }
    bool hasPathSum(TreeNode* root, int targetSum) {
        // 其实本质上是个树形的dfs
        if (!root) return false;
        if (!root->left && !root->right) return (targetSum - root->val) == 0;
        bool has_path = false;
        if (root->left) has_path |= hasPathSum(root->left, targetSum - root->val);
        if (root->right) has_path |= hasPathSum(root->right, targetSum - root->val);
        return has_path;
    }
};
