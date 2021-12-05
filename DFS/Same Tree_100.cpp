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
    bool dfs(TreeNode *p, TreeNode *q){
        if ((!p && q) || (p && ! q)) return false;
        if (!p && !q) return true;
        if (p->val != q->val) return false;
        else return dfs(p->right, q->right) && dfs(p->left, q->left);
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return dfs(p, q);
    }
};
