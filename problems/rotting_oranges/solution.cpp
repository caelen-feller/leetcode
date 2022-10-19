class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dir[] = {-1,0,1,0,-1};
       
        // BFS from every rotten orange, rotting as it goes, count depth
        queue<pair<int,int>> to_visit;
        pair<int,int> node;
        int fresh = 0;
        int i, j;

        for(i=0; i<m; i++) { // Find all rotten oranges and track no of fresh
            for(j=0; j<n; j++) {
                if(grid[i][j] == 2) to_visit.push({i, j});
                if(grid[i][j] == 1) fresh++;
            }   
        }
        
        // Simulate each minute (BFS for non-rotten oranges)
        int time = -1;
        while(!to_visit.empty()) { // when empty there are no more to rot
            int to_rot = to_visit.size(); // Amount of rotten oranges in grid
            while(to_rot-- > 0) { 
                node = to_visit.front(); to_visit.pop();
                
                for(int d = 0; d < 4; d++) { // Queue up next set of oranges to rot
                    i = node.first+dir[d];
                    j = node.second+dir[d+1];
                    
                    if(i>=0 and i<m and j>=0 and j<n and grid[i][j] == 1) { // rot if fresh
                        grid[i][j] = 2; 
                        to_visit.push({i,j}); // queue every new rotten orange
                        fresh--; 
                    }
                }  
            }
            time++; // increment time
        }

        if(fresh > 0) return -1;
        if(time==-1) return 0;
        return time;    }
};