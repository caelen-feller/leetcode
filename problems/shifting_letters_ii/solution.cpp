class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> shift_sum(s.size()+1,0);
        string s_out(s);
        for(int i = 0; i<shifts.size(); i++)
        {
            shift_sum[shifts[i][0]] += shifts[i][2] == 0 ? -1 : 1;
            shift_sum[shifts[i][1]+1] += shifts[i][2] == 0 ? 1 : -1;
        }
        for(int i= 1; i < s.size();i++)
            shift_sum[i] += shift_sum[i-1];
        
        for(int i = 0; i < s.size(); i++)
        {
            int change = shift_sum[i] % 26;
            if(change < 0) change = 26+change;
            s_out[i] = ((s_out[i]+change-'a') % 26) + 'a';
        }
        return s_out; 
    }
};