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
    TreeNode* insertIntoBST(TreeNode* root, int val) {

        if(root==NULL) return new TreeNode(val);
        TreeNode* curr=root;
        TreeNode* prev=NULL;

        while(curr){
            if(curr->val>val){
                if(curr->left==NULL && curr->val>val){
                    curr->left=new TreeNode(val);
                }
                curr=curr->left;
            }else{
                if(curr->right==NULL && curr->val<val){
                    curr->right=new TreeNode(val);
                }
                curr=curr->right;
            }
        }

        return root;
    }
};