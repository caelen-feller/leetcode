class Solution {
    int a=0,b=1,c=1,n_max=3,tmp;
public:
    int tribonacci(int n) {
        if(n == n_max) {
            tmp = c; c = a + b + c; a = b; b = tmp;
            n_max++; return c;
        }
        if(n == n_max-1) return c;
        if(n == n_max-2) return b;
        if(n == n_max-3) return a;

        return tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
    }
};