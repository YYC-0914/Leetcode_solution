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
    void dfs(TreeNode* ver, int k, vector<int> &a, vector<vector<int>> &res){
        if (!ver) return;
        // cout << " ver " << ver->val << " " << k << endl;
        if (!ver->left && !ver->right){
            if (k - ver->val == 0){
                a.push_back(ver->val);
                res.push_back(a);
                a.pop_back();
            return;
            }
        }
        a.push_back(ver->val);
        if (ver->left) dfs(ver->left, k - ver->val, a, res);
        if (ver->right) dfs(ver->right, k - ver->val, a, res);        
        a.pop_back();
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> a;
        dfs(root, targetSum, a, res);
        return res;
    }
};
