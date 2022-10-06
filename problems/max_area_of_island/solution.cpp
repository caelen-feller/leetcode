class Solution {
public:
    int dfs(vector<vector<int>> &grid, unsigned short x, unsigned short y, unsigned short nx, unsigned short ny) {
        if(grid[x][y] == 0) return 0;
        grid[x][y] = 0;
        
        unsigned int sum = 1;
        if(x > 0) sum += dfs(grid, x-1, y, nx, ny);
        if(x+1 < nx) sum += dfs(grid, x+1, y, nx, ny);
        if(y > 0) sum += dfs(grid, x, y-1, nx, ny);
        if(y+1 < ny) sum += dfs(grid, x, y+1, nx, ny);
        
        return sum;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area=0;
        int nx=grid.size();
        int ny=grid[0].size();

        for(int i=0;i<nx;i++)
            for(int j=0;j<ny;j++)
                if(grid[i][j]==1)
                    max_area=max(max_area, dfs(grid,i,j,nx,ny));
        return max_area;
    }
};

// class Solution {

// public:
//     int maxAreaOfIsland(vector<vector<int>>& grid) {
//         int neighbours[2][2] = {{-1,0},{0,-1}};
        
//         int nx = grid.size(), ny = grid[0].size();
//         int x,y,max_res = 0; 
        
//         for(x = 0; x<nx; x++) {
//             for(y = 0; y<ny; y++) {
//                 cout << "Processing " << x << ", " << y << endl;
//                 if(grid[x][y] == 0) continue;
//                 for(int *n : neighbours) { 
//                     if(x>0 && y>0) {
//                         grid[x][y] += grid[x + n[0]][y + n[1]];
//                     }
//                 }
//                 cout << "Value of tile "<< grid[x][y] << endl <<endl;
//                 max_res = grid[x][y] > max_res ? grid[x][y] : max_res;
//             }
//         }
//         return max_res;
//     }
// };