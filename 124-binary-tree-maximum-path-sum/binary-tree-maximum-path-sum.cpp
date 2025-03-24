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
    int pathsum(TreeNode* root,int& maxSum){
        if(root==NULL) return 0;
        int right=max(0,pathsum(root->left,maxSum));
        int left=max(0,pathsum(root->right,maxSum));

        maxSum=max(maxSum,root->val+right+left);

        return root->val+max(right,left);
    }
    int maxPathSum(TreeNode* root) {
        int maxSum=INT_MIN;
        pathsum(root,maxSum);
        return maxSum;
    }
};