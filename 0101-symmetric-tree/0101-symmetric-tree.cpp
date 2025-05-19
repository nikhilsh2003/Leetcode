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
    bool check(TreeNode* left,TreeNode* right) {
        if((!left and right) or (left and !right)) return false;
        if(!left and !right) return true;
        if(left->val!=right->val) return false;
        return check(left->left,right->right) and check(left->right,right->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return 1;
        return check(root->left,root->right);
    }
};