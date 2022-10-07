// def fib(n):
//     v1, v2, v3 = 1, 1, 0    # initialise a matrix [[1,1],[1,0]]
//     for rec in bin(n)[3:]:  # perform fast exponentiation of the matrix (quickly raise it to the nth power)
//         calc = v2*v2
//         v1, v2, v3 = v1*v1+calc, (v1+v3)*v2, calc+v3*v3
//         if rec=='1':    v1, v2, v3 = v1+v2, v1, v2
//     return v2


class Solution {
    unordered_map<int,int> fibs;

public:
    int fib(int n) {
        if(n < 2) return n;
        if(fibs.find(n) == fibs.end()) fibs[n] = (fib(n-1) + fib(n-2)); 
        return fibs[n];
    }
};

// class Solution {
    
// public:
//     int fib(int n) {
//         if(n<2) return n;
//         int v1 = 1, v2 = 1, v3 = 0 ,tmp;
//         string s = bitset<32>(n).to_string().substr(3);
//         for(char c : s) {
//             tmp = v2*v2;
//             v2 = (v1+v3)*v2;
//             v1 = v1*v1 + tmp;
//             v3 = tmp + v3*v3;
//             if( c == '1') {
//                 v2 = v1;
//                 v3 = v2;
//                 v1 = v2 + v3;
//             }
//         }
//         return v2;
//     }
// };
// class Solution {
//     int a=0,b=1,n_max=2,tmp;

// public:
//     int fib(int n) {
//         if(n < 2) return n;
//         if(n == n_max) {
//             tmp = b; b = a+b; a = tmp; 
//             n_max++; return b;
//         }
//         if(n == n_max-1) return b;
//         if(n == n_max-2) return a;
        
//         return fib(n-1) + fib(n-2);
//     }
// };