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
     int minoperation(vector<int>& arr) {
    vector<pair<int, int>> valueIndex; // Pair of value and original index
    for (int i = 0; i < arr.size(); i++) {
        valueIndex.push_back({arr[i], i});
    }

    // Sort the array based on the value to find correct positions
    sort(valueIndex.begin(), valueIndex.end());

    vector<bool> visited(arr.size(), false); // Track visited indices
    int swaps = 0;

    for (int i = 0; i < arr.size(); i++) {
        // If the element is already visited or in the correct position, skip it
        if (visited[i] || valueIndex[i].second == i) {
            continue;
        }

        // Find the size of the cycle
        int cycleSize = 0;
        int current = i;
        while (!visited[current]) {
            visited[current] = true;
            current = valueIndex[current].second; // Move to the next index in the cycle
            cycleSize++;
        }

        // Number of swaps needed for a cycle of size `cycleSize` is `cycleSize - 1`
        if (cycleSize > 1) {
            swaps += (cycleSize - 1);
        }
    }

    return swaps;
}

    int minimumOperations(TreeNode* root) {

        queue<TreeNode*>q;
        q.push(root);
        
        int operation=0;
        while(!q.empty()){
            int size=q.size();
            
            vector<int>arr;
            for(int i=0;i<size;i++){
                TreeNode* Node=q.front();
                q.pop();
                arr.push_back(Node->val);
                if(Node->left){
                    q.push(Node->left);

                }

                if(Node->right){
                    q.push(Node->right);
                }
            }

            operation+=minoperation(arr);
            


        }

        return operation;

        
    }
};