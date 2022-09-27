class Solution {
public:
    int romanToInt(string s) {
        // Parse into list of the following symbols and add:
        // "I", "V", "X", "L", "C", "D", "M"
        // "IV", "IX", "XL", "XC", "CD", "CM"
        // do this as a stream with one character look-ahead
        map <string, int> romans;
        romans["I"] = 1;
        romans["V"] = 5;
        romans["X"] = 10;
        romans["L"] = 50;
        romans["C"] = 100;
        romans["D"] = 500;
        romans["M"] = 1000;
        romans["IV"] = 4;
        romans["IX"] = 9;
        romans["XL"] = 40;
        romans["XC"] = 90;
        romans["CD"] = 400;
        romans["CM"] = 900;
        
        int out = 0;
        
        for(int i = 0; i<s.size(); i++)
        {
            int val = romans[s.substr(i,1)];
            if(i+1<s.size()) {
                int lookahead = romans[s.substr(i+1,1)];
                if(lookahead > val)
                {
                    val = romans[s.substr(i, 2)];
                    i++;
                }
            }
            out += val;
        }
        return out;
    }
};