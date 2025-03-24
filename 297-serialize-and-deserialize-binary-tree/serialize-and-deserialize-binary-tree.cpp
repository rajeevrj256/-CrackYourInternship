/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "X,";
        return to_string(root->val)+","+serialize(root->left)+serialize(root->right);



    }

    // Decodes your encoded data to tree.
    
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return buildtree(ss);
    }

    TreeNode* buildtree(stringstream & ss){
        string val;
        getline(ss,val,',');
        if(val=="X") return NULL;
        TreeNode* node=new TreeNode(stoi(val));
        node->left=buildtree(ss);
        node->right=buildtree(ss);

        return node;

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));