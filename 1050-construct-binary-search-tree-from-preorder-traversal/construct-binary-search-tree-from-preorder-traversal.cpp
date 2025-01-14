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
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.empty()) return nullptr;
        stack<TreeNode*>st;
        TreeNode* root=new TreeNode(preorder[0]);
        st.push(root);

        for(int i=1;i<preorder.size();i++){
            TreeNode* node=NULL;
            if(preorder[i]<st.top()->val){
                  node=st.top();
               TreeNode* child=new TreeNode(preorder[i]);
               node->left=child;
               st.push(child);
            }else{
                
                while(!st.empty() && st.top()->val<preorder[i]){
                    node=st.top();
                    st.pop();
                }
                
                TreeNode*child=new TreeNode(preorder[i]);
                node->right=child;
                st.push(child);
            }
        }
        return root;
    }
};