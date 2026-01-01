class Solution {
public:
    static bool cmp(int a,int b){
    string A=to_string(a);
    string B=to_string(b);

    return A+B>B+A;
}
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),cmp);
if(nums[0]==0) return "0";

        string ans="";
        for(int num:nums){
            ans+=to_string(num);
        }

        return ans;
    }
};