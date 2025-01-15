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
void inorder(TreeNode* root, vector<int> &ans){
    if(root == nullptr) return;
    inorder(root->left, ans);
    ans.push_back(root->val);
    inorder(root->right, ans);
}
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> ans;
        inorder(root, ans);

        int start = 0;

        int end = ans.size() - 1;
        int sum = -1;
        while(start < end){
            sum = ans[start] + ans[end];
            if(sum == k){
                return true;
            }else if(sum > k){
                end--;
            }else{
                start++;
            }
        }
        return false;
    }
};