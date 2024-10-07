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
int height(TreeNode* root){
    if (root==NULL) return 0;

    int lleft=height(root->left);
    int lright=height(root->right);

    if(lright>lleft){
        return lright+1;
    }
    else{
        return lleft+1;
    }
}
    int maxDepth(TreeNode* root) {
        return height(root);
    }
};