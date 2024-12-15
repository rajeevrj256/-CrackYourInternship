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
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* next=NULL;

        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
        
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
       // l1=reverse(l1);
        //l2=reverse(l2);

        ListNode* curr1=l1;
        ListNode* curr2=l2;
        
        ListNode* dummy=new ListNode(0);
        ListNode* next=dummy;
        while(l1 ||  l2  || carry){
            int sum=carry;

            if(l1){
                sum+=l1->val;
                l1=l1->next;
            }

            if(l2){
                sum+=l2->val;
                l2=l2->next;

            }

            carry=sum/10;
            next->next=new ListNode(sum%10);
            next=next->next;


        }

        //ListNode* final=reverse(dummy->next);


        //delete dummy;
        return dummy->next;

    }
};