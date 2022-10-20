// class Solution {
// public:
//     bool canPartition(vector<int>& nums) {
//         int sum = 0;
//         for (int num : nums) sum += num;

//         if (sum % 2) // If the sum is odd - we can never find two equal partitions
//             return false;
        
//         sum /= 2;

//         vector<bool> dp(sum+1); // dp keeps for each number if it has a subset or not
//         dp[0] = true;
        
//         for (auto a : nums) {
//             for (int i = sum; i >= a; i--) {
//                 dp[i] = dp[i] || dp[i-a]; // for each number, either we use it or we don't
//             } 
//         }
//         return dp[sum];
//     }
// };

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        const int MAX_NUM = 100;
        const int MAX_ARRAY_SIZE = 200;
        bitset<MAX_NUM * MAX_ARRAY_SIZE / 2 + 1> bits(1);
        int sum = 0;
        for (auto n : nums) {
            sum += n;
            bits |= bits << n;
        }
        return !(sum % 2) && bits[sum / 2];
    }
};