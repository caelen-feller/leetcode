class Solution {
public:
    string reverseWords(string s) {
        int n = s.size(), i = 0;
        char tmp;
        for(int j=0; j < n; j++)
        {
            if(s[j] == ' ') 
            {
                reverse(s.begin() + i, s.begin()+j);
                i = j+1;
            }
        }
        reverse(s.begin() + i, s.end());
        return s;
    }
};