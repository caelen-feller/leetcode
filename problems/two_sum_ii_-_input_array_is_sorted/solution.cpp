class Solution {
public:    
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int n = numbers.size(),j;
        vector<int> out(2);
        for(int i = 0; i<n; i++)
        {
           if(i == 0 || numbers[i] != numbers[i-1])
           {
               j = lower_bound(numbers.begin()+i, numbers.end(), target-numbers[i]) - numbers.begin();
               if(j == i) j++;
               if(j < n && numbers[j] == target - numbers[i]) 
               {
                   out[0] = i+1; out[1] = j+1;
                   return out;
               }
           }
        }
        return out;
    }
};