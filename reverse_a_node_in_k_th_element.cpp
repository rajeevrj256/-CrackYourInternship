/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
         vector<int>ans;
         ListNode*curr=head;
         while(curr){
            ans.push_back(curr->val);
            curr=curr->next;
         }
         
         int n=ans.size();
         for(int i=0;i+k<=n;i+=k){
            reverse(ans.begin()+i,ans.begin()+i+k);
         }
         

         ListNode* dummy=new ListNode(0);
         ListNode* temp=dummy;

         for(int i=0;i<ans.size();i++){
            temp->next=new ListNode(ans[i]);
            //temp=newNode;
            temp=temp->next;
         }

         return dummy->next;

    }
};