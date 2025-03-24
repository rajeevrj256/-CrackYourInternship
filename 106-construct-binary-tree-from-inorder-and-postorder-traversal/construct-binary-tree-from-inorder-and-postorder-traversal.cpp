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
   unordered_map<int,int>hash;
    TreeNode* build(vector<int>&inorder,int instart,int inend,int postend, vector<int>&postorder){

        if(instart>inend || postend<0) return NULL;

        int root_val=postorder[postend];
        TreeNode* node=new TreeNode(root_val);
        int idx=hash[root_val];
        int len=inend-idx;

        node->left=build(inorder,instart,idx-1,postend-len-1,postorder);
        node->right=build(inorder,idx+1,inend,postend-1,postorder);

        return node;
          
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int i=0;
        for(int num:inorder){
            hash[num]=i;
            i++;
        }

        int postend=postorder.size()-1;

        return build(inorder,0,inorder.size()-1,postend,postorder);

    }
};