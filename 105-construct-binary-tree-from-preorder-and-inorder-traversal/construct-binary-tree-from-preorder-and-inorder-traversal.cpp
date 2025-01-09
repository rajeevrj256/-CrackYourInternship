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
    unordered_map<int, int> inorder_map;  // To store value -> index for inorder traversal
    int preorder_index = 0;  // To keep track of current node in preorder    
    TreeNode* buildTreeHelper(const vector<int>& preorder, int inorder_left, int inorder_right) {
        // Base case: if there are no elements to construct the tree
        if (inorder_left > inorder_right) {
            return nullptr;
        }
        // The current root is the next element in preorder traversal
        int root_val = preorder[preorder_index++];
        TreeNode* root = new TreeNode(root_val);

        // Split the inorder array into left and right subtrees using the hashmap
        int inorder_index = inorder_map[root_val];

        // Recursively build the left and right subtrees
        root->left = buildTreeHelper(preorder, inorder_left, inorder_index - 1);
        root->right = buildTreeHelper(preorder, inorder_index + 1, inorder_right);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) { 
        // Build a hashmap to store the index of each value in inorder
        for (int i = 0; i < inorder.size(); ++i) {
            inorder_map[inorder[i]] = i;
        }
        
        // Start building the tree using helper function
        return buildTreeHelper(preorder, 0, inorder.size() - 1);
    }
};