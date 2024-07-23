class Solution
{
public:
    int minMoves2(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int mid = 0;
        if (n % 2 == 0)
        {
            if (nums[n / 2] > nums[n / 2 - 1])
            {
                mid = nums[n / 2];
            }
            else
            {
                mid = nums[n / 2 - 1];
            }
        }
        else
        {
            mid = nums[n / 2];
        }
        int count = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == mid)
            {
                continue;
            }
            count += abs(nums[i] - mid);
        }
        return count;
    }
};