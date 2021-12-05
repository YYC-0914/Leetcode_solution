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
    int dfs(TreeNode* ver){
        if (!ver) return 0x3f3f3f3f;
        if (!ver->left && !ver->right) return 1;
        return min(dfs(ver->left), dfs(ver->right)) + 1;
    }
    
    int minDepth(TreeNode* root) {
        if (! root) return 0;
        return dfs(root);
    }
};
