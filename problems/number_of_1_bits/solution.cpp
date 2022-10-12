class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t sum = 0;
        for(int j = 0; j<32; j++) {
            sum += n & 1;
            n = n >> 1;
        }
        return sum;
    }
};

//00000000000000000000000000001000 + 
//00000000000000000000000000000100