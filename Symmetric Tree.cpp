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
    bool check(TreeNode*left,TreeNode*right){
        if(!right && !left)return true;
        if(!left || !right)return false;
        if(right->val!=left->val)return false;
        
        return  check(right->right,left->left) && check(left->right,right->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)return true;
        return check(root->left,root->right);
    }
};n