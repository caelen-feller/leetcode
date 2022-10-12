class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(); 
        if (n < 2) return n ? nums[0] : 0;
        
        int pre_a = 0, pre_b = 0;
        int cur_a = nums[0], cur_b = 0;
        int temp;
        
        for (int i = 1; i < n-1; i++) {
            temp = max(pre_a + nums[i], cur_a);
            pre_a = cur_a;
            cur_a = temp;
            
            temp = max(pre_b + nums[i], cur_b);
            pre_b = cur_b;
            cur_b = temp;
        }
        cur_b = max(pre_b + nums[n-1], cur_b);
        
        return max(cur_a, cur_b);
    }

};

// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size(); 
//         if (n < 2) return n ? nums[0] : 0;
//         return max(robber(nums, 0, n - 1), robber(nums, 1, n));
//     }
// private:
//     int robber(vector<int>& nums, int l, int r) {
//         int pre = 0, cur = 0;
//         for (int i = l; i < r; i++) {
//             int temp = max(pre + nums[i], cur);
//             pre = cur;
//             cur = temp;
//         }
//         return cur;
//     }
// };