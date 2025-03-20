class Solution {
public:
    bool isPalindrome(int x) {
        int org = x;
        long int rev = 0;
        while(org > 0){
            int ld = org % 10;
            rev = rev * 10 + ld;
            org = org / 10;
        }
        if(rev == x) return true;
        return false;
    }
};