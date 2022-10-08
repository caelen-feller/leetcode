class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        for(int i = cost.size()-3; i >= 0; i--)
            cost[i] += min(cost[i+1], cost[i+2]);
        
        return min(cost[0], cost[1]);
    }
};

// class Solution {
// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n = cost.size();
//         vector<int> dp(3);  // dp[i] is minimum cost to reach to i_th floor
//         for (int i = 2; i <= n; i++) {
//             int jumpOneStep = dp[(i-1) % 3] + cost[i - 1];  // Minimum cost if we jump 1 step from floor (i-1)_th to i_th floor
//             int jumpTwoStep = dp[(i-2) % 3] + cost[i - 2];  // Minimum cost if we jump 2 steps from floor (i-2)_th to i_th floor
//             dp[i % 3] = min(jumpOneStep, jumpTwoStep);
//         }
//         return dp[n % 3];
//     }
// };

// Dynamic Programming Soln

// class Solution {
//     vector<int> * costptr;
//     int size, cost_min, a, b;
    
//     void findCost(int pos, int total) {
//         if(total >= cost_min) return;
//         if(pos > size-3)  { 
//             cost_min = total;
//             return;
//         }
        
//         findCost(pos+1,total + (*costptr)[pos+1]);
//         findCost(pos+2, total + (*costptr)[pos+2]);        
//     }
    
// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         size = cost.size();
//         costptr = &cost;
//         cost_min = INT_MAX;
//         if(size == 2) return min(cost[0], cost[1]);
//         findCost(1, cost[1]);
//         findCost(0, cost[0]);
//         return cost_min;
//     }
// };