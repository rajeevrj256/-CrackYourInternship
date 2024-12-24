class MyQueue {
public:
    stack<int>p;
    stack<int>q;
    MyQueue() {
        
    }
    
    void push(int x) {
        
            while(!q.empty()){
                p.push(q.top());
                q.pop();
            }
        

        p.push(x);
    }
    
    int pop() {
          while(!p.empty()){
            q.push(p.top());
            p.pop();
          }
          if(!q.empty()){
            int top=q.top();
            q.pop();
            return top;
          }

          return -1;
        
    }
    
    int peek() {
        while(!p.empty()){
            q.push(p.top());
            p.pop();
          }
          if(!q.empty()){
            int top=q.top();
            
            return top;
          }

          return 0;

    }
    
    bool empty() {
        return q.empty() && p.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */