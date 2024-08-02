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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int>ans;
        ListNode* curr=head;
        while(curr){
            ans.push_back(curr->val);
            curr=curr->next;
        }
        reverse(ans.begin()+left-1,ans.begin()+right);
        curr=head;
        int idx=0;
        while(curr){
            curr->val=ans[idx];
            curr=curr->next;
            idx++;
        }
        return head;
    }
};