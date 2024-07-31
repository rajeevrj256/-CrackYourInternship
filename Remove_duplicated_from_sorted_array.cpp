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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* dummy=new ListNode(0);
         dummy->next=head;
         ListNode* prev=dummy;
         ListNode* current=head;
         while(current){
            while(current->next && current->val==current->next->val){
                current=current->next;

            }

            if(prev->next==current){
                prev=prev->next;
            }else{
                prev->next=current->next;
            }
            current =current->next;

        }
        ListNode* newhead=dummy->next;
        delete dummy;
        


        return newhead;
        
    }
};