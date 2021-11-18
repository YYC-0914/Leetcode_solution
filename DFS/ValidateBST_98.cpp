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
    void dfs(vector<int> &res, TreeNode* root){
        if (! root) return;
        dfs(res, root->left);
        res.push_back(root->val);
        dfs(res, root->right);
    }
    
    bool isValidBST(TreeNode* root) {
         // inorder traversal 是一个从小到大的序列
        vector<int> res;
        dfs(res, root);
        for (int i = 1; i < res.size(); i ++) 
            if (res[i] <= res[i-1]) return false;
        return true;
    }
};
