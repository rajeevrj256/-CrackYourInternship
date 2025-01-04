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
        deque<TreeNode*>dq;
        dq.push_front(root);
        int movemenet=0;//0 --left to right  && 1--right to left;
        vector<vector<int>>ans;

        while(!dq.empty()){
            vector<int>res;
            int t=dq.size();

            for(int i=0;i<t;i++){
                TreeNode* top;
                if(movemenet==0){
                    top=dq.front();
                    dq.pop_front();
                    if(top->left){
                    dq.push_back(top->left);
                }

                if(top->right){
                    dq.push_back(top->right);
                }
                    
                }else{
                    top=dq.back();
                    dq.pop_back();
                if(top->right){
                    dq.push_front(top->right);
                }
                if(top->left){
                    dq.push_front(top->left);
                }

                }
                res.push_back(top->val);

            }

            ans.push_back(res);
            movemenet^=1;

        }

        return ans;
    }
};