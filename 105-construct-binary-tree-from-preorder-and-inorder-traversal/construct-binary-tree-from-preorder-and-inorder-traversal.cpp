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
    int rootIndex=0;
    TreeNode* solve(vector<int>&preorder,int Instart,int InEnd,unordered_map<int,int>&hash){

        if(Instart>InEnd){
            return NULL;
        }
        int rootval=preorder[rootIndex++];
        TreeNode* root=new TreeNode(rootval);

        int index=hash[rootval];
        


        root->left=solve(preorder,Instart,index-1,hash);
        root->right=solve(preorder,index+1,InEnd,hash);

        return root;

    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>hash;
        int i=0;
        for(int num:inorder){
            hash[num]=i;
            i++;

        }
        return solve(preorder,0,inorder.size()-1,hash);

        
    }
};