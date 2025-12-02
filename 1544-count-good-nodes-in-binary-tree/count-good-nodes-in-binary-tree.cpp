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
int count=0;
     void sol(TreeNode* root,int maxVal){
        if(root==NULL) return;

        if(root->val>=maxVal){
            count++;
        }

        sol(root->left,max(maxVal,root->val));
        sol(root->right,max(maxVal,root->val));
    }
    int goodNodes(TreeNode* root) {
        if(root==NULL) return 0;
        sol(root,root->val);
        return count;
    }
};