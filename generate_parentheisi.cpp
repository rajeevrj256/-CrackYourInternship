class Solution {
public:

void backtracking(vector<string>& result, string current, int open, int close, int max) {
        if (current.length() == max * 2) {
            result.push_back(current);
            return;
        }

        if (open < max) {
            backtracking(result, current + "(", open + 1, close, max);
        }
        if (close < open) {
            backtracking(result, current + ")", open, close + 1, max);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>str;
        backtracking(str,"",0,0,n);
        return str;
    }
};