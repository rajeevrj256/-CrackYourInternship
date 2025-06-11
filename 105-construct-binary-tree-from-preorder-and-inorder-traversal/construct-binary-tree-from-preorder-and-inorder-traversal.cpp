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
    TreeNode* solve(vector<int>&preorder,int preStart,int preEnd,vector<int>&inorder,int inStart,int inEnd,unordered_map<int,int>&hash){
        if(preStart>preEnd || inStart>inEnd) return NULL;
        TreeNode* root = new TreeNode(preorder[preStart]);
        int index=hash[preorder[preStart]];
        int leftpart=index-inStart;

        root->left=solve(preorder,preStart+1,preStart+leftpart,inorder,inStart,index-1,hash);
        root->right=solve(preorder,preStart+leftpart+1,preEnd,inorder,index+1,inEnd,hash);

        return root;


    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>hash;
        int n=inorder.size();
        for(int i=0;i<n;i++){
            hash[inorder[i]]=i;
        }
        
        return solve(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,hash);

    }
};