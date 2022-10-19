#define vvi vector<vector<int>>
#define vvb vector<vector<bool>>
#define vb vector<bool>

class Solution {
public:
	int n, m;

	// Go througout the adjacent if the adjacent's height is more or equal to current height
	void dfs(vvi& grid, vvb& flag, int x, int y) {
		flag[x][y] = true;
		if (x - 1 >= 0 && !flag[x - 1][y] && grid[x - 1][y] >= grid[x][y])
			dfs(grid, flag, x - 1, y);
		if (x + 1 < n && !flag[x + 1][y] && grid[x + 1][y] >= grid[x][y])
			dfs(grid, flag, x + 1, y);
		if (y - 1 >= 0 && !flag[x][y - 1] && grid[x][y - 1] >= grid[x][y])
			dfs(grid, flag, x, y - 1);
		if (y + 1 < m && !flag[x][y + 1] && grid[x][y + 1] >= grid[x][y])
			dfs(grid, flag, x, y + 1);
	}

	vvi pacificAtlantic(vvi& heights) {
		n = heights.size();
		m = heights[0].size();

		vvb flag1(n, vb(m)), flag2(n, vb(m));
		vvi ans;

		// Pacific
		// Do DFS starting from upper border and left border
		// Mark true in flag1 if posibble
		for (int i = 0; i < n; i++)
			dfs(heights, flag1, i, 0);
		for (int i = 1; i < m; i++)
			dfs(heights, flag1, 0, i);

		// Attlantic
		// DFS starting from bottom border and right border
		// Mark true in flag2 if posibble
		for (int i = 0; i < n; i++)
			dfs(heights, flag2, i, m - 1);
		for (int i = 0; i < m - 1; i++)
			dfs(heights, flag2, n - 1, i);

		// Add cordinate to ans if both flag1 and flag2 is equal to true
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
			if (flag1[i][j] && flag2[i][j])
				ans.push_back({i, j});

		return ans;
	}
};


// // Pac: L, T
// // At: R, B
// // Given heights of each cell
// // rain water - can flow to adjacent cells lower
// // find watershed - cells which can flow to both oceans.

// // Finding paths which allow a cell to reach both ocean borders
// // Fails if Reaches dead ends on all paths before both oceans
// // Corners always work - if bigger than corner or corner connected it works

// /* 
// 1 2 2 3 5 -> P P P P P -> P_ P_ P_ P_ PA
// 3 2 3 4 4 -> P P P P P -> 
// 2 4 5 3 1 -> P P _ 3 1 
// 6 7 1 4 5 -> P P 1 4 5 -> PA PA _A _A _A
// 5 1 1 2 4 -> P 1 1 2 4 -> PA _A _A _A _A etc


// Spiral breaks the two pass, need to do BFS in from borders

// */

// class Solution {
//     int dir[5] = {-1,0,1,0,-1};
//     vector<vector<int>> ans;

// public:
//     vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
//         int n = heights.size(), m = heights[0].size();
        
//         queue<pair<int,int>> to_visit_a, to_visit_p;
//         vector<vector<unsigned short>> watershed(n, vector<unsigned short>(m, 0));
        
//         // Add borders
//         for(int i = 1; i < m-1; i++) {
//             to_visit_p.push({0, i}); watershed[0][i] += 1;
//             to_visit_a.push({n-1, m-1-i}); watershed[n-1][i] += 2;
//         }
//         to_visit_p.push({0,m-1}); to_visit_a.push({0,m-1}); watershed[0][m-1] = 3;

//         for(int i = 1; i < n-1; i++) {
//             to_visit_p.push({i, 0}); watershed[i][0] += 1;
//             to_visit_a.push({n-1-i, m-1}); watershed[i][m-1] += 2;
//         }
//         to_visit_p.push({n-1,0}); to_visit_a.push({n-1,0}); watershed[n-1][0] = 3;
        
//         spread_watershed(n, m, heights, to_visit_p, watershed, 1);
//         spread_watershed(n, m, heights, to_visit_a, watershed, 2);
        
//         for(int i = 0; i < n; i++)
//             for(int j = 0; j < m; j++)
//                 if(watershed[i][j] == 3) ans.push_back({i,j});
        
//         return ans;
//     }
    
//     void spread_watershed(int n, int m, vector<vector<int>>& heights, queue<pair<int,int>> &to_visit, 
//         vector<vector<unsigned short>> &watershed, int offset) {
        
//         pair<int,int> node;
//         int i, j, h;
        
//         while(!to_visit.empty()) {
//             node = to_visit.front(); to_visit.pop();
//             // cout << "Processing node (" << node.first <<", "<< node.second << ")= " << watershed[node.first][node.second]<<endl;
            
//             for(int d = 0; d < 4; d++) { // Queue up next set of watersheds to spread
//                 i = node.first+dir[d];
//                 j = node.second+dir[d+1];
//                 h = heights[node.first][node.second];
//                 if(i>=0 and i<n and j>=0 and j<m) {
//                     // cout << i << j << h <<endl;

//                     if(watershed[i][j] != offset and watershed[i][j] != 3) { // not spread already
//                         if(heights[i][j] >= h) { // spread if smaller
//                             to_visit.push({i,j}); // queue every new watershed
//                             watershed[i][j] += offset; //goes to offset or 3.
//                             // cout << "Spreading to (" << i <<", "<< j << ") -> " << watershed[i][j] <<endl;
//                         }
//                     }
//                 }
//             }  
//         }
//     }
// };
