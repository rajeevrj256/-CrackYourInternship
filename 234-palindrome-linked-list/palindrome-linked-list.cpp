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

    void rev(ListNode*& head){
        ListNode* prev=NULL;
        ListNode* next=NULL;
        ListNode* curr=head;

        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head=prev;
        
    }
    bool isPalindrome(ListNode* head) {

        if(!head || !head->next)return true;
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        rev(slow);

        ListNode*first=head;
        ListNode*second=slow;

        while(second){
            if(first->val!=second->val)return false;

            first=first->next;
            second=second->next;
        }
 return true;

        




    }
};