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
           if (lists[i]) {
                minheap.push({lists[i]->val, lists[i]});
            }

        }


        ListNode* dummy=new ListNode(0);
        ListNode*newhead=dummy;

        while(!minheap.empty()){
            ListNode* node = minheap.top().second;
            minheap.pop();
            newhead->next=node;
            newhead=newhead->next;
            if(node->next){
                minheap.push({node->next->val,node->next});
            }
        }

        return dummy->next;
    }
};