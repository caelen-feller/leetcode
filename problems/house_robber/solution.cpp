class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n<2) return nums[0];
        // 1 2 3 1 -> 1 2 4 3
        // 2 7 9 3 1 -> 2 7 11 10 12
        if(n >= 3) nums[2] += nums[0];
        for(int i = 3; i < n; i++) {
            nums[i] += max(nums[i-2], nums[i-3]);
        }
        
        return max(nums[n-1], nums[n-2]);
    }
};