/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    void adjacentmatric(TreeNode* root,vector<vector<int>>&adj){
        if(root==NULL)return;

        if(root->left){
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
            
        adjacentmatric(root->left,adj);
        }

        if(root->right){
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
        adjacentmatric(root->right,adj);
        }



    }

    void dfs(vector<vector<int>>&adj,vector<int>&res,vector<bool> &vis,int target,int k,int count){
        if(count==k){
              res.push_back(target);
              return;
        }
        vis[target] = true;
        for(int neighbor:adj[target]){
            if(!vis[neighbor]){
                dfs(adj,res,vis,neighbor,k,count+1);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<vector<int>>adj(501);
        adjacentmatric(root,adj);
        vector<int>res;
       vector<bool> visited(501, false);
        dfs(adj,res,visited,target->val,k,0);
        return res;


        // TreeNode* curr=root;
        // queue<TreeNode*>q;
        // while(curr){
        //     if(curr->data==target)break;
        //     q.push(curr);
        //     if(curr->left)curr=curr->left;

        //     else{
        //         curr=q.front();
        //         q.pop();
        //         curr=curr->right;
        // }


        

    }
};