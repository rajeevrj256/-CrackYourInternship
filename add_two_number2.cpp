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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;

        while (l1 != NULL) {
            s1.push(l1 -> val);
            l1 = l1 -> next;
        }

        while (l2 != NULL) {
            s2.push(l2->val);
            l2 = l2->next;
        }

        int carry = 0;
        int totalSum = 0;
        ListNode *ans = new ListNode();
        ListNode *temp = NULL;

        while (!s1.empty() || !s2.empty()) {
            if (!s1.empty()) {
                totalSum += s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                totalSum += s2.top();
                s2.pop();
            }
            carry = totalSum / 10;
            ListNode* newHead = new ListNode(totalSum % 10);
            newHead -> next = temp;
            temp = newHead;
            totalSum = carry;
        }

        if (carry != 0) {
            ListNode* newHead = new ListNode(carry);
            newHead->next = temp;
            temp = newHead;
        }
        return temp;
    }
};