class Solution {
public:
    int maxProduct(vector<int>& A) {
        int ans = A[0], dpMin = A[0], dpMax = A[0], n = size(A);
        int pMin;
        for(int i = 1; i < n; i++) {
            if(A[i] < 0) {
                pMin = dpMin;
                dpMin = dpMax;
                dpMax = pMin;
            }
            dpMin = min(A[i], A[i] * dpMin);
            dpMax = max(A[i], A[i] * dpMax);
            ans = max(ans, dpMax);
        }
        return ans;
    }
};

// class Solution {
// public:
//     int maxProduct(vector<int> A) {
//         int n = A.size(), res = A[0], p = 1;
//         for (int i = 0; i < n; i++) {
//             if(l == 0) l = A[i];
//             else l *= A[i];
//             res = max(res, l);
//             if(r == 0) r = A[n - 1 - i];
//             else r *= A[n - 1 - i];
//             res = max(res, r);
//         }
//         return res;
//     }
// };