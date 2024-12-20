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
        int flag=1;
        while(!q.empty()){
            vector<int>store;
            int t=q.size();
            while(t--){
                TreeNode* node=q.front();
                q.pop();
                if(node->left){
                    store.push_back(node->left->val);
                    q.push(node->left);

                }

                if(node->right){
                    store.push_back(node->right->val);
                    q.push(node->right);
                }
            }
            if(flag && store.size()>0){
                int t=q.size();
                int i=store.size()-1;

               while(t--){
                    TreeNode* node=q.front();
                    q.pop();
                    node->val=store[i];
                    q.push(node);
                    i--;
               }

            }
               flag=!flag;


        }
            return root;

    }
};