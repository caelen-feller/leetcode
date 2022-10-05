class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, l=1, max_l=1, n = s.size(), j;
        if(n==0) return 0;
        char tmp;
        while(i+l < n)
        {
            tmp = s[i+l];
            for(j = 0; j<l; j++) if(tmp == s[i+j]) break;
            if(j < l) {
                if(max_l < l) max_l = l;
                i += j+1;
                l -= j+1;
            }
            else l++;
        }
        return max_l < l ? l : max_l;
    }
};