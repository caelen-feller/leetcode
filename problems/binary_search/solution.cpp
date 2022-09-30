class Solution {
public:
    int search(vector<int>& nums, int target) {
        int sz = nums.size();
        if(sz == 1) return nums[0] == target ? 0 : -1;
        
        int pivot = nums.size() / 2;
        int lb, ub, tmp;
        lb = 0;
        ub = nums.size()-1;

        while(nums[pivot] != target)
        {
            sz = ub - lb;        
            if(sz <= 1) 
            {
                if(nums[pivot] == target) return pivot;
                if(nums[lb] == target) return lb;
                if(nums[ub] == target) return ub;
                return -1;
            }
            cout << pivot << ", " << lb << ", " << ub << endl;
            if(nums[pivot] > target)
            {
                ub = pivot;
                pivot = (pivot - lb)/2  + lb;
            }
            if(nums[pivot] < target)
            {
                tmp = pivot;
                pivot = (ub-pivot)/2 + pivot;   
                lb = tmp;
            }
            
        }
        return pivot;
    }
};