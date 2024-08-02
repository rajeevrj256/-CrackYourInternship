class Solution {
  public:
    void rearrangeEvenOdd(Node *head) {
        // Your Code here
  Node*oddstart=NULL;
        Node*oddend=NULL;
        
        Node*evenstart=NULL;
        Node*evenend=NULL;
        
        Node* curr=head;
        int index=1;
        while(curr){
           // int val=curr->val;
            
            if(index%2!=1){
                if(evenstart==NULL){
                    evenstart=curr;
                    evenend=evenstart;
                }else{
                    evenend->next=curr;
                    evenend=evenend->next;
                }
            }else{
                if(oddstart==NULL){
                    oddstart=curr;
                    oddend=oddstart;
                }else{
                    oddend->next=curr;
                    oddend=oddend->next;
                }
            }
            curr=curr->next;
            index++;
        }
        
        if(oddstart==NULL || evenstart==NULL)return;
        
        oddend->next=evenstart;
        evenend->next=NULL;
        
        head=oddstart;
    }
};
      