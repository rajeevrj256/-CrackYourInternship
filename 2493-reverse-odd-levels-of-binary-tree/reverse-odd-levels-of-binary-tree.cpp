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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        bool flag=false;
        while(!q.empty()){
            vector<TreeNode*>store;
            int t=q.size();
            while(t--){
                TreeNode* node=q.front();
                q.pop();
                store.push_back(node);
                if(node->left){
                   
                    q.push(node->left);

                }

                if(node->right){
                    
                    q.push(node->right);
                }
            }
            if(flag){
                int t=q.size();
                int i=0;
                int j=store.size()-1;

               while(i<j){
                    swap(store[i]->val,store[j]->val);
                    i++;
                    j--;
               }

            }
               flag=!flag;


        }
            return root;

    }
};