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
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL)return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<int>ans;
        while(!q.empty()){
            
            
            vector<int>levelElement;
            int maxi=INT_MIN;

            int t=q.size();
            while(t--){
                TreeNode* Node=q.front();
                q.pop();
                if(Node !=NULL){

                maxi=max(maxi,Node->val);

                if(Node->left){
                    q.push(Node->left);
                }

                if(Node->right){
                    q.push(Node->right);
                }
                }
            }
            ans.push_back(maxi);
        }

        return ans;
    }
};