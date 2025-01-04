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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
    if (!root) return result;
        map<int,map<int,multiset<int>>>mp;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            TreeNode* node=p.first;
            int index=p.second.first;
            int level=p.second.second;

            mp[index][level].insert(node->val);

            if(node->left){
                q.push({node->left,{index-1,level+1}});

            }
            if(node->right){
                q.push({node->right,{index+1,level+1}});
            }
        }
        
        for (auto& [index,level] : mp) {
            vector<int>vertical;
            for(auto& [l,val]:level){
                vertical.insert(vertical.end(), val.begin(), val.end());
            }
        result.push_back(vertical);
    }

        return result;
        
    }
};