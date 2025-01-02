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
    vector<vector<int>> levelOrder(TreeNode* root) {

        if(!root)return {};
        queue<TreeNode*>q;
        int level=0;
        q.push(root);

        vector<vector<int>>ans;
        while(!q.empty()){
            vector<int>levelElement;
            int s=q.size();

            for(int i=0;i<s;i++){
                TreeNode* node=q.front();
                q.pop();
                
                levelElement.push_back(node->val);
                if(node->left){
                    q.push(node->left);
                }

                if(node->right){
                    q.push(node->right);
                }
            }
            ans.push_back(levelElement);
            
        }

        return ans;
    }
};