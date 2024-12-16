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
    void reverse(ListNode* head){
        ListNode* curr=head;
        ListNode* next=NULL;
        ListNode* prev=NULL;

        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head= prev;

    }
    ListNode* kthnode(ListNode* temp,int k){
        while(k>1 && temp!=NULL){
                   temp=temp->next;
                   k--;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*curr=head;
        ListNode*prev=NULL;

        while(curr){
            ListNode*knode=kthnode(curr,k);

            if(knode==NULL){
                prev->next=curr;
                break;
            }

            ListNode* nextnode=knode->next;

            knode->next=NULL;
            reverse(curr);

            if(curr==head){
                head=knode;
            }else{
                prev->next=knode;
            }
            prev=curr;
            curr=nextnode;


        }

        return head;
    }
};