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
    bool isPalindrome(ListNode* head) {
        string s="";
        ListNode* curr=head;
        while(curr){
            s+=to_string(curr->val);
            curr=curr->next;
        }
        string rev=s;
        reverse(s.begin(),s.end());
        return s==rev;
    }
};