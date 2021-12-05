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
    int minDepth(TreeNode* root) {
        if (! root) return 0;
        if (!root->left  && !root->right) return 1;
        int res = 0x3f3f3f3f;
        if (root->left) res = min(res, minDepth(root->left));
        if (root->right) res = min(res, minDepth(root->right));
        return res + 1;
    }
};
