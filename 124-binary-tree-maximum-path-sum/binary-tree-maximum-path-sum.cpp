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
    int path(TreeNode*root,int& pathvalue){
        if(root==NULL)return 0;

        int left=max(0,path(root->left,pathvalue));
        int right=max(0,path(root->right,pathvalue));

        pathvalue=max(pathvalue,left+right+root->val);

        return max(left,right)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        if(root==NULL) return 0;
        int pathvalue=INT_MIN;

        path(root,pathvalue);

        return pathvalue;
    }
};