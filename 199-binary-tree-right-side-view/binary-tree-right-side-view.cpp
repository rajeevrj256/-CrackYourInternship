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
    vector<int> rightSideView(TreeNode* root) {

        if(root==NULL) return {};
      
        queue<TreeNode*>q;
        vector<int>ans;
        q.push(root);
        while(!q.empty()){
            

            int rightmost=0;
            int size=q.size();
            while(size--){
                
                TreeNode* temp=q.front();
                q.pop();
                rightmost=temp->val;

                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);


            }
            ans.push_back(rightmost);

        }

       
       
        return ans;
    }
};