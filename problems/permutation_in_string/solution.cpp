class Solution {
    bool areVectorsEqual(vector<int> a, vector<int> b){
        for(int i=0; i<26; i++){
            if(a[i]!=b[i]) return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        if(n2<n1) return false;
        vector<int> freqS1(26, 0);
        for(char c: s1) freqS1[c-'a']++;
        
        vector<int> freqS2(26, 0);
        int i=0, j=0;
        
        while(j<n2){
           
            if(freqS1[s2[j] - 'a'] == 0)
            {
                if(n2-j < n1) return false;
                fill(freqS2.begin(), freqS2.end(), 0);
                j++; i = j; continue;
            }
             
            freqS2[s2[j]-'a']++;
            if(freqS2[s2[j] - 'a'] > freqS1[s2[j] - 'a'])
            {
                
                while(s2[i] != s2[j]) {
                    freqS2[s2[i]-'a']--; i++; 
                }
                if(s2[i] == s2[j]) {
                    freqS2[s2[i]-'a']--; i++; 
                } 
            }
            
            if(j-i+1==n1) return true;
    
            
            if(j-i+1<n1) j++;
            else{
                freqS2[s2[i]-'a']--;
                i++;
                j++;
            }
        }
        return false;
    }
};
