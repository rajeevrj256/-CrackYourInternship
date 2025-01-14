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
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    int kthSmallest(TreeNode* root, int k) {
        int leftSubtreeSize = countNodes(root->left);
        
        if (k == leftSubtreeSize + 1) {
            // Current node is the k-th smallest element
            return root->val;
        } else if (k <= leftSubtreeSize) {
            // Search in the left subtree
            return kthSmallest(root->left, k);
        } else {
            // Search in the right subtree, adjusting k
            return kthSmallest(root->right, k - leftSubtreeSize - 1);
        }
    }
};
