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
    void help(TreeNode* root, vector<int>& ans, vector<string>& res) {
        if (root == NULL) return;
        
        ans.push_back(root->val);  // Add the current node to the path
        
        if (root->left == NULL && root->right == NULL) {
            // If it's a leaf node, we need to form the path string and add it to the result
            string s = to_string(ans[0]);
            for (int i = 1; i < ans.size(); i++) {
                s += "->" + to_string(ans[i]);
            }
            res.push_back(s);
        }
        
        // Traverse left and right subtrees
        help(root->left, ans, res);
        help(root->right, ans, res);
        
        ans.pop_back();  // Backtrack after processing the node
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        vector<int> ans;  // To store the path
        if (root != NULL) help(root, ans, res);
        return res;
    }
};
