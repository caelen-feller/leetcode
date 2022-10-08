class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), max_d = n+m, min_d;
        
        // Use left and top neighbours
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(mat[i][j] == 0) continue;
                min_d = max_d;
                if(i > 0 and mat[i-1][j]+1 < min_d) min_d = mat[i-1][j]+1;
                if(j > 0 and mat[i][j-1]+1 < min_d) min_d = mat[i][j-1]+1;
                mat[i][j] = min_d;
            }
        }
        
        //use right and bottom neighbours
        for(int i=m-1; i>=0; i--) {
            for(int j=n-1; j>=0; j--) {
                if(mat[i][j] == 0) continue;
                min_d = max_d;
                if(i < m-1 and mat[i+1][j]+1 < min_d) min_d = mat[i+1][j]+1;
                if(j < n-1 and mat[i][j+1]+1 < min_d) min_d = mat[i][j+1]+1;
                mat[i][j] = min(min_d, mat[i][j]);
            }
        }
        
        return mat;
    }
};