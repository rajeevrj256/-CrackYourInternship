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
    int post_index;
    TreeNode* solve(vector<int>&postorder,int Instart,int Inend){
        if(Instart>Inend)return NULL;

        int rootval=postorder[post_index--];
        TreeNode* root=new TreeNode(rootval);

        int index=hash[rootval];

        root->right=solve(postorder,index+1,Inend);
        root->left=solve(postorder,Instart,index-1);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int i=0;
        for(int num:inorder){
            hash[num]=i;
            i++;
        }
        post_index=postorder.size()-1;

        return solve(postorder,0,inorder.size()-1);


    }
};