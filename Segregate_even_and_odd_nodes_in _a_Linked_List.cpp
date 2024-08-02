class Solution {
  public:
    Node* divide(Node* head) {
        // code here
        Node*oddstart=NULL;
        Node*oddend=NULL;
        
        Node*evenstart=NULL;
        Node*evenend=NULL;
        
        Node* curr=head;
        
        while(curr){
            int val=curr->data;
            
            if(val%2==0){
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
        }
        
        if(oddstart==NULL || evenstart==NULL)return head;
        
        evenend->next=oddstart;
        oddend->next=NULL;
        
        
        
        return evenstart;
        
    }
};
