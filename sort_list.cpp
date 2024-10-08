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
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode*temp=NULL;
        while(fast!=NULL && fast->next!=NULL){
            temp=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        temp->next=NULL;

        ListNode* left=sortList(head);
        ListNode* right=sortList(slow);

        return merge(left,right);


    }
    ListNode* merge(ListNode* left,ListNode* right){

        ListNode* ptr=new ListNode(0);
        ListNode* curr=ptr;

        while(left!=NULL && right!=NULL){
            if(left->val<=right->val){
                curr->next=left;
                left=left->next;
            }else{
                curr->next=right;
                right=right->next;
            }
            curr=curr->next;
        }
        if(left!=NULL){
            curr->next=left;
            left=left->next;
        }
        if(right!=NULL){
            curr->next=right;
            right=right->next;
        }
        return ptr->next;
    }
};