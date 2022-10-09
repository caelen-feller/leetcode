class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> hash;
        int a, b,diff;
        for (int i = 0; i < nums.size(); i++) {
            diff = target - nums[i];
            if (hash.find(diff) != hash.end()) {
                a = hash[diff];
                b = i;			
                return {a,b};
            }

            hash[nums[i]] = i;
        }
        return {a,b};
    }
};