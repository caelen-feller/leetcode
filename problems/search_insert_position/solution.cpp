class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low,high,pivot;
        low = 0;
        high = nums.size()-1;
        if(nums[0] >= target) return 0;
        if(nums[high] < target) return high+1;
        while(high - low > 1)
        {
            pivot = low + (high-low)/2;
            if(nums[pivot] == target) return pivot;
            if(nums[low] == target) return low;
            if(nums[high] == target) return high;
            if(nums[pivot] > target) high=pivot;
            if(nums[pivot] < target) low=pivot;
        }
        return high;
        
    }
};