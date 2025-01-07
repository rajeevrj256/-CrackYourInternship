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
    int widthOfBinaryTree(TreeNode* root) {

        if(root==NULL)return 0;
        deque<pair<TreeNode*,long long>>q;
        q.push_back({root,0});

        long long maxi=INT_MIN;

        while(!q.empty()){
            int t=q.size();
            long long  start=q.front().second;
            long long end=q.back().second;
            maxi=max(maxi,end-start+1);
            for(int i=0;i<t;i++){
                TreeNode* node=q.front().first;
                int index=q.front().second;
                q.pop_front();

                long long  relindex=index-start;

               
                if(node->left)q.push_back({node->left,2*relindex+1});
                if(node->right)q.push_back({node->right,2*relindex+2});
            }
           
        }
        return maxi;
    }
};