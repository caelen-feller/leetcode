class Solution {
public:
    void solve(int i,int n,int k,vector<vector<int>>&ans,vector<int> v) {
        if(k==0) {
            ans.push_back(v);
            return;
        }
       
        if(k==n-i)
        {
            v.push_back(i+1);
            solve(i+1,n,k-1,ans,v);
        }
        
        else
        {
            for(int j=i;j<n+1-k;j++)
            {
                v.push_back(j+1);
                solve(j+1,n,k-1,ans,v);
                v.pop_back();
            }
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> v;
        solve(0,n,k,ans,v);
        return ans;
    }
};