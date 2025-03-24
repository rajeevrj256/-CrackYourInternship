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
        if(root==NULL) return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>res;
        while(!q.empty()){
            int t=q.size();
            vector<int>ans;
            while(t--){
                TreeNode* top=q.front();
                ans.push_back(top->val);
                q.pop();

                if(top->left){
                    q.push(top->left);
                }

                if(top->right){
                    q.push(top->right);
                }
            }
            res.push_back(ans);
        }

        return res;
    }
};