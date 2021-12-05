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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        vector<vector<int>> res;
        vector<int> a;
        if (! root) return res;
        int cur_lev = 0;
        q.push({root, 0});
        while (q.size()){
            auto ver = q.front();
            q.pop();
            TreeNode* p = ver.first;
            int l = ver.second;
            if (l == cur_lev){
                a.push_back(p->val);
            }
            else{
                res.push_back(a);
                a.clear();
                a.push_back(p->val);
                cur_lev = l;
            }
            TreeNode * l1 = p->left;
            TreeNode * l2 = p->right;
            if (l1){
                q.push({l1, l + 1});
            }
            if (l2){
                q.push({l2, l + 1});
            }
        }
        res.push_back(a);
        return res;
    }
};
