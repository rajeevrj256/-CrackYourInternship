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
    ListNode* reverse(ListNode* head){
        if(head==NULL){
            return NULL;
        }
        ListNode*prev=NULL;
        ListNode*curr=NULL;
        ListNode*next=head;
        while(next){
            curr=next;
            next=curr->next;
            curr->next=prev;
            prev=curr;
        }
        head=prev;
        return head;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* rev= reverse(slow);

        while(rev){
            if(head->val!=rev->val)return false;

            head=head->next;
            rev=rev->next;
        }

        return true;


        
    }
};