class Solution {
public:
    bool isSame(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL || subRoot == NULL) {
            return root == subRoot;
        }

        return (root->val == subRoot->val) &&
               isSame(root->left, subRoot->left) &&
               isSame(root->right, subRoot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL) return false; // If the main tree is empty, it can't contain subRoot.

        // Check if current tree matches subRoot OR check in left subtree OR check in right subtree.
        return isSame(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
