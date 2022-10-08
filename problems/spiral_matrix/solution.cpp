class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = n, top = 0, bottom = m, count = 0, i,j;
        vector<int> out(m*n);
        vector<vector<int>> sim(matrix);
        
        while(left<right) {
            for(i = left; i < right; i++) sim[top][i] = count++;
            top++; if(top>=bottom) break;
            for(i = top; i < bottom; i++) sim[i][right-1] = count++;
            right--; if(left>=right) break;
            for(i = right-1; i >= left; i--) sim[bottom-1][i] = count++;
            bottom--; if(top>=bottom) break;
            for(i = bottom-1; i >= top; i--) sim[i][left] = count++;
            left++;

        }

        for(i = 0; i < m; i++) {
            for(j = 0; j < n; j++) {
                out[sim[i][j]] = matrix[i][j];
            }
        }
        return out;
    }
};