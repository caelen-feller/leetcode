class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), i, first_zero;
        for(i = 0; i<n; i++)
        {
            if(nums[i] == 0) 
            {
                first_zero = i;
                break;
            }
        }
        for(; i<n; i++)
        {
            if(nums[i] != 0)
            {
                nums[first_zero] = nums[i];
                nums[i] = 0;
                first_zero++;
            }
        }
    }
};