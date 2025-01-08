class Solution {
public:
    vector<int> result;
    unordered_map<TreeNode*, TreeNode*> parentMap;
    unordered_set<TreeNode*> visited;

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        buildMap(root);
        findTarget(target, 0, k);
        return result;
    }

    void buildMap(TreeNode* node) {
        if (node->left != nullptr) {
            parentMap[node->left] = node;
            buildMap(node->left);
        }
        if (node->right != nullptr) {
            parentMap[node->right] = node;
            buildMap(node->right);
        }
    }

    void findTarget(TreeNode* node, int distance, int k) {
        if (node == nullptr || visited.count(node)) {
            return;
        }
        visited.insert(node);

        if (distance == k) {
            result.push_back(node->val);
            return;
        }
        if (node->left != nullptr) {
            findTarget(node->left, distance + 1, k);
        }
        if (node->right != nullptr) {
            findTarget(node->right, distance + 1, k);
        }
        if (parentMap.count(node)) {
            findTarget(parentMap[node], distance + 1, k);
        }
    }
};