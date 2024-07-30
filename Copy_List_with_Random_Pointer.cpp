/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
       if (head == nullptr) return nullptr;

        // Create a mapping from original nodes to their copies
        unordered_map<Node*, Node*> nodeMap;

        // Step 1: Create new nodes with next pointers only and store in map
        Node* curr = head;
        Node* newHead = new Node(curr->val);
        nodeMap[curr] = newHead;

        Node* newCurr = newHead;
        curr = curr->next;

        while (curr) {
            newCurr->next = new Node(curr->val);
            newCurr = newCurr->next;
            nodeMap[curr] = newCurr;
            curr = curr->next;
        }

        // Step 2: Assign random pointers using the map
        curr = head;
        newCurr = newHead;

        while (curr) {
            if (curr->random) {
                newCurr->random = nodeMap[curr->random];
            }
            curr = curr->next;
            newCurr = newCurr->next;
        }

        return newHead;
        
    }
};