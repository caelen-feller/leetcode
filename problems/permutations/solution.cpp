class Solution {
public:
    void solve(int i, int n, vector<vector<int>> &ans, vector<int> &nums) {
        if(i == n) {
            ans.push_back(nums); return;
        }
        
        for(int j = i; j < n; j++) {
            swap(nums[j],nums[i]);
            solve(i+1, n, ans, nums);
            swap(nums[j],nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        solve(0, nums.size(), ans, nums);
        return ans;
    }
};