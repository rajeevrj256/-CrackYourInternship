class MyCircularQueue {
public:
    class Node{
        public:
        int val;
        Node* next;

        Node(int val){
             this->val = val;
            this->next = nullptr;
        }
    };
    int size;
    int insertCount;
    Node * head ;
    Node* curr;
    MyCircularQueue(int k) {
        size=k;
        insertCount=0;
        head=NULL;
        curr=NULL;
    }
    
    bool enQueue(int value) {
        
        if(isFull())return false;

        Node* temp=new Node(value);

        if(isEmpty()){
            head=temp;
            curr=temp;
            temp->next=temp;
            
        }else{
            temp->next=head;
            curr->next=temp;
            curr=temp;
        }
        insertCount++;


        return true;

    }
    
    bool deQueue() {
        if(isEmpty())return false;
        if(head==curr){
            delete head;
            head=NULL;
            curr=NULL;

        }else{

        Node* temp=head;
        head=head->next;
        curr->next=head;
        delete temp;
        }
        insertCount--;

        return true;
        
    }
    
    int Front() {
        return (isEmpty()?-1:head->val);
    }
    
    int Rear() {
        return (isEmpty()?-1:curr->val);
    }
    
    bool isEmpty() {
        return insertCount==0;
    }
    
    bool isFull() {
        return insertCount==size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */