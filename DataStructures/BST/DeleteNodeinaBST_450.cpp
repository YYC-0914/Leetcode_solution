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
    int successor(TreeNode* ver){
        ver = ver->right;
        while (ver->left) ver = ver->left;
        return ver->val;
    }
    int predecessor(TreeNode* ver){
        ver = ver->left;
        while (ver->right) ver = ver->right;
        return ver->val;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        // 这题中学习了BST中很重要的两个概念：predecessor and successor
        // 一般来说在树结构中使用递归可以省去维护父节点的工作
        if (! root) return nullptr;
        if (key > root->val) root->right = deleteNode(root->right, key);
        else if (key < root->val) root->left = deleteNode(root->left, key);
        else{
            if (! root->left && ! root->right) return nullptr;
            else if (root->right){
                root->val = successor(root);
                root->right = deleteNode(root->right, root->val);
            }
            else{
                root->val = predecessor(root);
                root->left = deleteNode(root->left, root->val);
            }
        }
        return root;
    }
};
