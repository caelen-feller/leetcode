class Solution {
public: 
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), next;
        vector<vector<int>> out(m+1, vector<int>(n));
        
        for(int i = m; i >= 0; i--) { 
            for(int j = 0; j < n; j++) {
                if(i == m) {
                    out[i][j] = j;
                    continue;
                }
                next = j + grid[i][j];
                if(next < 0 or next >= n or grid[i][j] != grid[i][next]) out[i][j] = -1;
                else out[i][j] = out[i+1][next];                    
            }
        }
        
        return out[0];
    }
};


// class Solution {
// public:
//     int followBall(vector<vector<int>>& grid, int i, int j, int n, int m) {
//         if(i == m) return j;
//         int next = j+grid[i][j];
//         if(next < 0 or next >= n) return -1;
//         if(grid[i][j] != grid[i][next]) return -1;
//         return followBall(grid, i+1, next, n, m);
//     }
    
//     vector<int> findBall(vector<vector<int>>& grid) {
//         int m = grid.size(), n = grid[0].size();
//         vector<int> out(n);
//         for(int j = 0; j < n; j++) out[j] = followBall(grid, 0, j, n, m);
//         return out;
//     }
// };

// class Solution {
// public:
//     vector<int> findBall(vector<vector<int>>& grid) {
//         int m = grid.size(), n = grid[0].size(), dir;
//         vector<int> out(n);
//         iota(out.begin(), out.end(), 0);
        
//         for(int i = 0; i < m; i++) {
//             for(int j = 0; j < n; j++) {
//                 if(out[j] > -1) {
//                     dir = grid[i][out[j]];
//                     out[j] += dir;
//                     if(out[j] < 0 or out[j] == n) out[j] = -1;
//                     else if(grid[i][out[j]] != dir) out[j] = -1;
//                 }
//             }
//         }
//         return out;
//     }
// };