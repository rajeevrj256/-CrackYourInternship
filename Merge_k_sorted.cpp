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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>ans;
        for(ListNode* i:lists){
            while(i){
                ans.push_back(i->val);
                i=i->next;
            }
        }
        sort(ans.begin(),ans.end());

        ListNode* curr=new ListNode(0);
        ListNode*temp=curr;

        for(int i :ans){
           temp->next = new ListNode(i);
            temp=temp->next;
        }
        return curr->next;


    }
};