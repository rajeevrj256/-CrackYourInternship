class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        // Your code here
        stack<int>s;
        for(char c:S){
            if(isdigit(c)){
                s.push(c-'0');
            }else{
                int b=s.top();
                s.pop();
                int a=s.top();
                s.pop();
                int d;
                if(c=='*'){
                    d=a*b;
                }else if(c=='/'){
                    d=a/b;
                }else if(c=='+'){
                    d=a+b;
                }else{
                    d=a-b;
                }
                
                s.push(d);
            }
        }
        if(s.empty())return 0;
        return s.top();
        
    }
};
