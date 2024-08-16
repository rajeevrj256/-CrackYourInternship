class Solution {
    private:
    bool isPalindrome(const string&s,int left,int right){
        while(left<right){
            if(s[left]!=s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
public:

void backtracking(string& s,vector<vector<string>>&res,vector<string>&substring,int index){
    if(index==s.length()){

    res.push_back(substring);
    return;
    }

    for(int i=index+1;i<=s.length();i++){
        if(isPalindrome(s,index,i-1)){

        substring.push_back(s.substr(index,i-index));
        backtracking(s,res,substring,i);
        substring.pop_back();
        }
        

        
    }

    
}

    vector<vector<string>> partition(string s) {
        vector<string>substring;
        vector<vector<string>>res;
        backtracking(s,res,substring,0);
        return res;



    }
};