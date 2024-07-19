class Solution {
public:
    int calculate(string s) {
        stack<int> numbers;
        stack<char> operators;
        int curr = 0;
        char last_operator = '+';
        
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            
            if (isdigit(c)) {
                curr = curr * 10 + (c - '0');
            }
            
            if (!isdigit(c) && !isspace(c) || i == s.size() - 1) {
                if (last_operator == '+') {
                    numbers.push(curr);
                } else if (last_operator == '-') {
                    numbers.push(-curr);
                } else if (last_operator == '*' || last_operator == '/') {
                    int top = numbers.top();
                    numbers.pop();
                    if (last_operator == '*') {
                        numbers.push(top * curr);
                    } else {
                        numbers.push(top / curr);
                    }
                }
                last_operator = c;
                curr = 0;
            }
        }
        
        int result = 0;
        while (!numbers.empty()) {
            result += numbers.top();
            numbers.pop();
        }
        
        return result;
    }
};
