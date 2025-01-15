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
class BSTIterator {
public:
    TreeNode* head=NULL;
    void flattern(TreeNode* root){
       TreeNode* curr=root;
       TreeNode* prev=NULL;
       TreeNode* lastNode=NULL;

       while(curr){
        if(curr->left==NULL){
            if(lastNode){
                lastNode->right=curr;
            }else{
                head=curr;
            }

            lastNode=curr;
            
            curr=curr->right;
        }else{
            prev=curr->left;
            while(prev->right && prev->right!=curr){
                prev=prev->right;
            }

            if(prev->right==NULL){
                prev->right=curr;
                curr=curr->left;
            }else{
                prev->right=NULL;
                if(lastNode){
                    lastNode->right=curr;
                }else{
                    head=curr;
                }
                lastNode=curr;
                
                curr=curr->right;
            }
        }
    
       }
   
    }

    BSTIterator(TreeNode* root) {
        flattern(root);
       
    }
    
    int next() {
        int ans = head->val;
        head = head->right;
        return ans;

       
        
    }
    
    bool hasNext() {
        return head!=NULL;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */