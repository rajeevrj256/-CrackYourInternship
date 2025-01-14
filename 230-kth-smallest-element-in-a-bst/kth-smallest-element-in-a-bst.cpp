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
    int res=0;
    void inorderK(TreeNode*root,int k,int& count){
        if(root==NULL) return;

        inorderK(root->left,k,count);
        count++;
        if(count==k){
            res=root->val;
            return;

        }
        inorderK(root->right,k,count);

        


    }
    int kthSmallest(TreeNode* root, int k) {
        int count=0;
        inorderK(root,k,count);
        return res;
    }
};