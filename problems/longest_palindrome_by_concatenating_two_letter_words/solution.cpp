class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int a[26*26] = {0};
        int n = words.size();
        int x, y;
        int sum = 0;
        
        for(int i = 0; i < n; i++) { 
            x = words[i][0] - 'a'; y = words[i][1] - 'a';
            if(a[y*26 + x]) { sum+=4; a[y*26 + x]--; }
            else a[x*26 + y]++; 
        }
        
        for(int i = 0; i < 26; i++) {
            if(a[i*26 + i]) {
                sum += 2;
                break;
            }
        }
        
        return sum;
    }
};