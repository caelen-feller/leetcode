class Solution {
public:
    int search(vector<int>& nums, int target) {
        // search [0,n) for pivot
        // 4 5 6 (7 > 0) 1 2
        // [start,end] - if mid is less than start pivot is in [start,mid].
        // if mid < target normal search on [mid,end]
        // else its in [start, mid]
        
        // if mid is greater than start then pivot is in [mid,end].
        // if this is the case and mid > target target is in in [start,mid] with no edit.
        // otherwise it's in [mid,end]
        
        int n = nums.size();
        
        if(n<50) { // linear search for small array
            for(int i = 0; i<n; i++) if(nums[i] == target) return i;
            return -1;
        }
        
        int l = 0, r=n-1, m;
        bool pre_pivot = target > nums[n-1]; // target between start and pivot
        
        while(l<r) {
            m = (l + r - 1) >> 1;
            
            if(nums[l] < nums[r]) { // pivot outside search area
                if (nums[m] < target) l = m + 1; // target in [m, r]
                else r = m; // pivot and target in [l,m]
            }
            else { // pivot in search area
                if(nums[m] < nums[l]) { // pivot in [l,m]
                    if(pre_pivot) r = m;
                    else if(nums[m] < target) l = m+1;
                    else r = m;
                }
                else { // pivot in [m+1,r]
                    if(!pre_pivot) l = m + 1;
                    else if(nums[m] >= target) r = m;
                    else l = m + 1;
                }
            }
        }
        
        if(nums[r] == target) return r;
        return -1;
    }
};