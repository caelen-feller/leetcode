class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int closest = nums[0]+nums[1]+nums[2];

        sort(nums.begin(), nums.end());
        int curSum;
        int first, second, third; 
        for(int first = 0; first < n-2 ; first++) { // Iterate till all at end
            second = first+1; third = n-1;
            if(first > 0 && nums[first] == nums[first-1]) continue; // skip if repeat (won't change total)                   
            while(second < third) {
                int curSum = nums[first]+nums[second]+nums[third];
                if(curSum == target) return curSum;
                if(abs(target-curSum)<abs(target-closest)) closest = curSum;
                if(curSum > target) --third;
                else ++second;
            }
        }
        return closest;
    }
};