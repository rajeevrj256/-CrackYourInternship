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
    void help(TreeNode* root,int& mini,int& prev){
        if(root==NULL)return;

        
        help(root->left,mini,prev);

        mini=min(mini,abs(prev-root->val));
        prev=root->val;
        help(root->right,mini,prev);
    }
    int getMinimumDifference(TreeNode* root) {
        int mini=INT_MAX;
        int prev=INT_MAX;
        help(root,mini,prev);

        return mini;
    }
};