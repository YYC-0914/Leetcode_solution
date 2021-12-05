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
    // 自底向上先算出所有节点的高度，这样做的话复杂度会低一些
    int dfs(TreeNode* root){
        if (! root) return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);
        if (l == -1 || r == -1 || abs(l-r) > 1) return -1;
        else return max(l, r)  + 1;
    }
    bool isBalanced(TreeNode* root) {
        if (dfs(root) == -1) return false;
        else return true;
    }
};
