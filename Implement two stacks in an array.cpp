class twoStacks {
  public:
    stack<int>s1;
    stack<int>s2;

    twoStacks() {}

    // Function to push an integer into the stack1.
    void push1(int x) {
        s1.push(x);
    }

    // Function to push an integer into the stack2.
    void push2(int x) {
        s2.push(x);
    }

    // Function to remove an element from top of the stack1.
    int pop1() {
        if(!s1.empty()){
            int a=s1.top();
            s1.pop();
            return a;
            
        }
        return -1;
    }

    // Function to remove an element from top of the stack2.
    int pop2() {
         if(!s2.empty()){
            int a=s2.top();
            s2.pop();
            return a;
        }
        return -1;
    }
};
