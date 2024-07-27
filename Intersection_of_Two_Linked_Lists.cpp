/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;

    ListNode *pA = headA;
    ListNode *pB = headB;

    // Traverse both lists
    while (pA != pB) {
        // When pA reaches the end of list A, move it to the beginning of list B
        pA = (pA == nullptr) ? headB : pA->next;
        // When pB reaches the end of list B, move it to the beginning of list A
        pB = (pB == nullptr) ? headA : pB->next;
    }

    // Either both pointers are nullptr (no intersection), or both are at the intersection node
    return pA;
    }
};