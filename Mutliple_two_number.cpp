class solution {
  public:
    long long multiplyTwoLists(Node *first, Node *second) {
        // code here
        long long  l1=0;
        long long l2=0;
        
        while(first!=NULL){
            l1=(l1*10+first->data)%1000000007;
            first=first->next;
        }
        while(second!=NULL){
            l2=(l2*10+second->data)%1000000007;
            second=second->next;
        }
        
        long long  n=l1*l2;
        
        
        return n%1000000007;
        
    }
};