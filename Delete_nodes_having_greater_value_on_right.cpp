class Solution {
public:
    Node* compute(Node* head) {
        if (!head) return NULL; // Handle empty list
        
        // Reverse the linked list
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;
        
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        head = prev; // Update head to the new front of the reversed list
        
        // Traverse the reversed list and keep track of the max value seen so far
        Node* maxNode = head;
        curr = head;
        
        while (curr && curr->next) {
            if (curr->next->data < maxNode->data) {
                // Delete the next node
                Node* temp = curr->next;
                curr->next = temp->next;
                delete temp;
            } else {
                // Move to the next node
                curr = curr->next;
                maxNode = curr;
            }
        }
        
        // Reverse the list again to restore the original order
        prev = NULL;
        curr = head;
        
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        head = prev; // Update head to the new front of the restored list
        
        return head;
    }
};
