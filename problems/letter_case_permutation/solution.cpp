class Solution {
public:
    char flipCase(char c) {
        if(c - 'A' < 27) c = (c - 'A') + 'a';
        else c = (c-'a') + 'A';
        
        return c;        
        
    }
    
    void solve(int i, int n, string& s, vector<string> &ans) {
        if(i == n) return;
        solve(i+1, n, s, ans);
        if(s[i] - '0' < 10) return;
        s[i] = flipCase(s[i]);
        solve(i+1, n, s, ans);
        ans.push_back(s);
        s[i] = flipCase(s[i]);
    }
    
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        ans.push_back(s);
        solve(0, s.size(), s, ans);
        return ans;
    }
};