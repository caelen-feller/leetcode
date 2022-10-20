class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, l=1, max_l=1, n = s.size(), j;
        if(n==0) return 0;
        while(i+l < n)
        {
            for(j = 0; j<l; j++) if(s[i+l] == s[i+j]) break;
            if(j++ < l) { // repetition
                max_l = max(l, max_l);
                i += j;
                l -= j;
            }
            l++;
        }
        return max_l < l ? l : max_l;
    }
};