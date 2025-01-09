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
    TreeNode* solve(vector<int>&preorder,int preStart,int preEnd,vector<int>&inorder,int Instart,int InEnd,unordered_map<int,int>&hash){

        if(preStart>preEnd || Instart>InEnd){
            return NULL;
        }
        int rootval=preorder[preStart];
        TreeNode* root=new TreeNode(rootval);

        int index=hash[rootval];
        int leftsubtreeSize=index-Instart;


        root->left=solve(preorder,preStart+1,preStart+leftsubtreeSize,inorder,Instart,index-1,hash);
        root->right=solve(preorder,preStart+leftsubtreeSize+1,preEnd,inorder,index+1,InEnd,hash);

        return root;

    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>hash;
        int i=0;
        for(int num:inorder){
            hash[num]=i;
            i++;

        }
        return solve(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,hash);

        
    }
};