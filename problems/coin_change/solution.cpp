class Solution {
public:
    int coinChange(vector<int>& coins, int n) {
        // creating the base dp array, with first value set to 0
        int dp[++n];
        dp[0] = 0;
        // more convenient to have the coins sorted
        sort(begin(coins), end(coins));
        // populating our dp array
        for (int i = 1; i < n; i++) {
            // setting dp[0] base value to 1, 0 for all the rest
            dp[i] = INT_MAX;
            for (int c: coins) {
                if (i - c < 0) break;
                // if it was a previously not reached cell, we do not add use it
                if (dp[i - c] != INT_MAX) dp[i] = min(dp[i], 1 + dp[i - c]);
            }
        }
        return dp[--n] == INT_MAX ? -1 : dp[n];
    }
};

// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         if(amount == 0) return 0;
        
//         // speed up traversal
//         sort(coins.begin(), coins.end());
        
//         int dp_n = amount + 1;//amount/coins[0] + 1;
//         // can get better bounds if know max and min
//         vector<int> dp(amount +1 , amount + 1);
//         dp[0] = 0;
//         int n_coins = upper_bound(coins.begin(), coins.end(), amount) - coins.begin();
//         if(n_coins == 0) return -1;
//         int k;
        
//         if(amount/coins[n_coins-1] > 10) {
//             for (int i = 1; i < dp_n; i++) {
//                 k = upper_bound(coins.begin(), coins.begin() + n_coins, i) - coins.begin();
//                 for (int j = 0; j < k; j++) {
//                     dp[i] = min(dp[i], dp[i - coins[j]] + 1);
//                 }
//             }
//         } else { 
//             for (int i = 1; i < dp_n; i++) {
//                 for (int j = 0; j < n_coins; j++) {
//                     if(coins[j] <= i)
//                         dp[i] = min(dp[i], dp[i - coins[j]] + 1);
//                 }
//             }
//         }
//         return dp[amount] > amount ? -1 : dp[amount];
//     }
// };
// class Solution {
//     vector<int> dp, coins;
//     int n_coins, coin_max;
    
//     int get_dp(int amount) { 
//         if(dp[amount] < coin_max) return dp[amount];

//         int k = upper_bound(coins.begin(), coins.begin() + n_coins, amount) - coins.begin();
//         cout << amount << " " << k << endl;
//         int tmp;
//         for(int j = 0; j < k; j++) {
//             tmp = get_dp(amount - coins[j]);
//             if(tmp == -1) continue;
//             dp[amount] = min(dp[amount], tmp + 1);
//         }

//         return dp[amount] == coin_max ? -1 : dp[amount];
//     }
    
// public:
//     int coinChange(vector<int>& c, int amount) {
//         if(amount == 0) return 0;
//         coins = c;
//         sort(coins.begin(), coins.end());
//         coin_max = amount + 1;
//         dp = vector<int>(coin_max, coin_max);
//         dp[0] = 0;
//         n_coins = upper_bound(coins.begin(), coins.end(), amount) - coins.begin();
//         if(n_coins == 0) return -1;
        
//         // init special cases
//         // Special cases - any multiple of the biggest coin is known

//         return get_dp(amount);
//     }
// };
// // 0 (0+1) ()