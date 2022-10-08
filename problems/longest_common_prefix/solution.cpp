class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int prefix = strs[0].size();
        for(int i = 0; i < strs.size(); i++) {
            for(int j = 0; j < prefix; j++) {
                if(strs[0][j] != strs[i][j]) prefix = j;
            }
        }
        return strs[0].substr(0,prefix);
    }
};