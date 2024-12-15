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
   ListNode* merge(ListNode* left,ListNode* right){
       ListNode* dummy=new ListNode(0);
       ListNode* temp=dummy;
       while(left && right){
         if(left->val<=right->val){
            
            temp->next=left;
            left=left->next;
         }else{
           
            temp->next=right;
            right=right->next;
         }

         

         temp=temp->next;
       }
       if(left){
            temp->next=left;
            
         }
         if(right){
            temp->next=right;
            
         }
       return dummy->next;

   }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=NULL;

        while(fast && fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=NULL;
        ListNode* left=sortList(head);
        ListNode* right=sortList(slow);
        return merge(left,right);



    }
};