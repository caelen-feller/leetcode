class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        deque<int> kn;
        
        int yj = lower_bound(arr.begin(), arr.end(), x)-arr.begin();
        int yi = yj-1;
        if (yj == 0) return vector<int>(arr.begin(), arr.begin()+k); 
        if (yj == arr.size()) return vector<int>(arr.end()-k, arr.end()); 
        
        if(arr[yj] == x) 
        {
            kn.push_back(x);
            yj++;
        }
        
        while(kn.size() < k)
        {
            
            if(yi < 0) while(kn.size() < k) kn.push_back(arr[yj++]);   
            else if(yj >= arr.size()) while(kn.size() < k) kn.push_front(arr[yi--]);
            else
            {
                int di = x - arr[yi];
                int dj = arr[yj] - x; 
                if(di <= dj) 
                {
                    kn.push_front(arr[yi]);
                    yi--;
                }
                else
                {
                    kn.push_back(arr[yj]);
                    yj++;
                }      
            }
        }                
        
        vector<int> out(kn.begin(), kn.end());
        return out;
    }
};