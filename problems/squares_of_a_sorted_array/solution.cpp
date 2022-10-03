class Solution {
public:
    
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> nums_sq(n,0);
        int i = 0; int j = n-1;
        unsigned int tmp_i, tmp_j;
        tmp_i = nums[i] * nums[i];
        tmp_j = nums[j] * nums[j];
        
        for(int x = n-1; x >=0; x--)
        {     
            if(tmp_i < tmp_j)
            {
                nums_sq[x] = tmp_j; 
                if(--j < 0 || nums[j] <= 0) tmp_j = 0; 
                else tmp_j = nums[j] * nums[j];
            }
            else 
            {
                nums_sq[x] = tmp_i;
                if(++i == n || nums[i] >= 0) tmp_i = 0; 
                else tmp_i = nums[i] * nums[i];
            }
        }
            
        return nums_sq;
    }
};