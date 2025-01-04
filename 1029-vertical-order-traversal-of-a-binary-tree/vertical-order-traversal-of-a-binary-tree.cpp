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

    static bool cmp(pair<int,int>a,pair<int,int>b){
        if(a.first==b.first) return a.second<b.second;
        return a.first<b.first;
    }
    void helper(TreeNode*root,int level,int row,map<int,vector<pair<int,int>>>&hash){
        if(root==NULL)return;
        hash[level].push_back({row,root->val});
        helper(root->left,level-1,row+1,hash);
        helper(root->right,level+1,row+1,hash);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root==NULL) return {};

        map<int,vector<pair<int,int>>>hash;
        helper(root,0,0,hash);

        vector<vector<int>>ans;
        for(auto i:hash){
           vector<int>levelValue;

           sort(i.second.begin(),i.second.end(),cmp);

           for(auto&value:i.second){
            levelValue.push_back(value.second);
           }

           ans.push_back(levelValue);




        }

        return ans;
        
    }
};