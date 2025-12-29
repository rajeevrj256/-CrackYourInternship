class Solution {
public:
    void sortColors(vector<int>& nums) {
        int countRed=0;
        int countWhite=0;
        int countBlue=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) countRed++;
            if(nums[i]==1) countWhite++;
            if(nums[i]==2) countBlue++;
        }


        for(int i=0;i<countRed;i++){
            nums[i]=0;
        }

        for(int i=countRed;i<countRed+countWhite;i++){
            nums[i]=1;
        }

        for(int i=countRed+countWhite;i<nums.size();i++){
            nums[i]=2;
        }
        
    }
};