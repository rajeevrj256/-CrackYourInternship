class Solution {
public:
    bool isNumber(string s) {
         int n = s.size();
    int i = 0;

    // Skip leading whitespaces
    while (i < n && std::isspace(s[i])) i++;
    
    // Check for sign
    if (i < n && (s[i] == '+' || s[i] == '-')) i++;

    bool isNumeric = false;
    bool isDotSeen = false;
    bool isESeen = false;

    while (i < n) {
        if (std::isdigit(s[i])) {
            isNumeric = true;
        } else if (s[i] == '.') {
            if (isDotSeen || isESeen) return false;
            isDotSeen = true;
        } else if (s[i] == 'e' || s[i] == 'E') {
            if (isESeen || !isNumeric) return false;
            isESeen = true;
            isNumeric = false; // Need a number after 'e' or 'E'
            if (i < n - 1 && (s[i + 1] == '+' || s[i + 1] == '-')) i++; // Skip next sign
        } else {
            return false;
        }
        i++;
    }

    // Skip trailing whitespaces
    while (i < n && std::isspace(s[i])) i++;

    return isNumeric && i == n;
    }
};