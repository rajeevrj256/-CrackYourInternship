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
     int minoperation(vector<int>&arr){
      map<int,int>hash;
       vector<int>temp(arr.begin(),arr.end());
       sort(temp.begin(),temp.end());
       for(int i=0;i<temp.size();i++){
        hash[temp[i]]=i;
       }


       int operation=0;
       for(int i=0;i<arr.size();){
        int idx=hash[arr[i]];
        if(idx==i){
            i++;
        }else{
            swap(arr[i],arr[idx]);
            operation++;
        }
       }

       return operation;
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