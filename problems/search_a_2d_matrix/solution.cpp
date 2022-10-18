class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int left, right;

        if(m < 100) {
            left = 0; right = m-1;
            while(left < n && right >= 0){
                if(matrix[left][right] == target) return true;
                else if(matrix[left][right] > target) right--;
                else left++;
            }
            return false;
        }
        
        left = 0;
        right = m*n-1;
        int mid;
        
        while(right!=left) {
            mid = (left + right - 1) >> 1;
            if (matrix[mid / m][mid % m] < target) left = mid + 1;
            else right = mid;
        }
        return matrix[right / m][right % m] == target;
    }
};