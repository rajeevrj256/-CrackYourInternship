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
    TreeNode* helper(vector<int>&preorder,int prestart,int prend,vector<int>&postorder,int poststart,int postend,unordered_map<int,int>map){
           if(prestart>prend || poststart>postend)return NULL;

           TreeNode* root=new TreeNode(preorder[prestart]);
           if (prestart == prend) return root;
           int leftSubtreeRoot = preorder[prestart + 1];
           int inroot=map[leftSubtreeRoot];
           int numsleft=inroot-poststart+1;

           root->left=helper(preorder,prestart+1,prestart+numsleft,postorder,poststart,inroot,map);
           root->right=helper(preorder,prestart+1+numsleft,prend,postorder,inroot+1,postend-1,map);

           return root;

    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int,int>hash;
        for(int i=0;i<postorder.size();i++){
            hash[postorder[i]]=i;

        }
        return helper(preorder,0,preorder.size()-1,postorder,0,postorder.size()-1,hash);
    }
};