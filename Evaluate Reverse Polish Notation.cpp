#include <vector>
#include <string>
#include <stack>
#include <stdexcept>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& expression) {
        stack<int> s; // Stack to hold operands

        for (const string& token : expression) {
            // If the token is a number, push it onto the stack
            if (isdigit(token[0]) || (token[0] == '-' && token.length() > 1)) { // Handle negative numbers
                s.push(stoi(token));
            } else {
                // Otherwise, it's an operator
                int right = s.top(); s.pop(); // Pop the right operand
                int left = s.top(); s.pop(); // Pop the left operand

                switch (token[0]) {
                    case '+':
                        s.push(left + right);
                        break;
                    case '-':
                        s.push(left - right);
                        break;
                    case '*':
                        s.push(left * right);
                        break;
                    case '/':
                        s.push(left / right);
                        break;
                    default:
                        throw invalid_argument("Invalid operator: " + token);
                }
            }
        }
        
        return s.top(); // Return the final result
    }
};
