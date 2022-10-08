class Solution {
    int a=1,b=2,n_max=3,tmp;

public:
    int climbStairs(int n) {
        if(n < 3) return n;
        if(n == n_max) {
            tmp = b; b = a+b; a = tmp; 
            n_max++; return b;
        }
        if(n == n_max-1) return b;
        if(n == n_max-2) return a;
        
        return climbStairs(n-1) + climbStairs(n-2);
    }
};