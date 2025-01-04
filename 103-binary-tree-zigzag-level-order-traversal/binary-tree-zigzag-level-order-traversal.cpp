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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)return {};

        queue<TreeNode*>q;
        q.push(root);

        int movement=0;

        vector<vector<int>>ans;

        while(!q.empty()){
            int t=q.size();
            vector<int>leveltra(t);
            for(int i=0;i<t;i++){
                TreeNode* top=q.front();
                q.pop();

                int index=(movement==0?i:t-1-i);
                leveltra[index]=top->val;

                if(top->left)q.push(top->left);
                if(top->right)q.push(top->right);

            }
                movement^=1;
            ans.push_back(leveltra);



        }

        return ans;
    }
};