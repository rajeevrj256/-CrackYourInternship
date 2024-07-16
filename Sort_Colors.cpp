class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map <int,int>hash;
        for(int num:nums){
            hash[num]++;
        }
        int k=0;
        for(int i=0;i<3;i++){
            
           while(hash[i]>0){
            nums[k++]=i;
            hash[i]--;
           }


        }
        
    }
};