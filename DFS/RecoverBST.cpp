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
    void change_val(TreeNode* root, int x, int y, int cnt ){
        if (root){
            if (root->val == x || root->val == y){
                root->val = root->val == x ? y : x;
            }
            change_val(root->left, x, y, cnt), change_val(root->right, x, y, cnt);
        }

    }
    
    void recoverTree(TreeNode* root) {
        // 在中序遍历的数组中找到那两个错误的数，然后再做一遍中序遍历把他们俩换了
        vector<int> res;
        vector<int> idx;
        dfs(res, root);
        for (int i = 0; i < res.size() - 1; i++){
            if (res[i] > res[i+1])
                idx.push_back(i);
        }
        // for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        // puts("");
        // cout << idx.size() << endl;
        if (idx.size() != 2) idx.push_back(idx[0] + 1);
        else idx[1]++;
        change_val(root, res[idx[0]], res[idx[1]], 2);
        // cout << res[idx[0]] << " " << res[idx[1]];
        return;
    }
};
