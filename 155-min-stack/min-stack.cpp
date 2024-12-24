class MinStack {
public:
    stack<pair<int, int>> s;
    int mini=INT_MIN;
    MinStack() {
        
    }
    
    void push(int val) {

       if(s.empty()){
        s.push({val,val});
       }else{
        int currentmin=s.top().second;
        s.push({val,min(val,currentmin)});
       }

    }
    
    void pop() {
        s.pop();
    }
    
    int top() {

        auto top= s.top();
        return top.first;
    }
    
    int getMin() {
        auto top=s.top();
        return top.second;
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */