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
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>minheap;

        for(int i=0;i<lists.size();i++){
            ListNode*curr=lists[i];
            while(curr){
                minheap.push({curr->val,curr});
                curr=curr->next;
            }

        }

        ListNode* dummy=new ListNode(0);
        ListNode*newhead=dummy;

        while(!minheap.empty()){
            newhead->next=minheap.top().second;
            newhead=newhead->next;
            minheap.pop();
        }

        return dummy->next;
    }
};