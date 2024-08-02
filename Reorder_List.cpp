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
    ListNode*reverseL(ListNode* head){
        ListNode *prev=NULL;
        ListNode* curr=NULL;
        ListNode* next=head;
        while(next){
            curr=next;
            next=curr->next;
            curr->next=prev;
            prev=curr;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* curr=head;
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode*rev=reverseL(slow->next);
        slow->next=nullptr;

        ListNode*str=head;

        while(str && rev){
            ListNode*temp1=str->next;
            ListNode*temp2=rev->next;

            str->next=rev;
            rev->next=temp1;
            rev=temp2;
            str=temp1;

        }
        
        
    }
};