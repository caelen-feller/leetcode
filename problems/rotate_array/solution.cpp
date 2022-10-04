class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        if(k == 0) return;
        auto b = nums.begin(), e = nums.end();
        reverse(b, e - k);
        reverse(e - k, e);
        reverse(b, e);
    }
};