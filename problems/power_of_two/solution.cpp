class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && not (n & n - 1);
    }
};

// int in binary
// 101011... = 2^n + ... + 2^0
// want exactly one non-zero bit