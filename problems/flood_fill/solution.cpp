// DFS Stack
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int target = image[sr][sc];
        if(target == color) return image;
        int nx = image.size(), ny = image[0].size();
        vector<vector<int>> out(image);
        stack<pair<int,int>> to_visit;
        to_visit.push(make_pair(sr,sc));
        pair<int,int> tmp;
        
        while(!to_visit.empty()) {
            tmp = to_visit.top();
            to_visit.pop();
            out[tmp.first][tmp.second] = color;
            
            if(tmp.first > 0 && out[tmp.first-1][tmp.second] == target)
                to_visit.push(make_pair(tmp.first - 1, tmp.second));
            if(tmp.first+1 < nx && out[tmp.first+1][tmp.second] == target)
                to_visit.push(make_pair(tmp.first+1, tmp.second));
            if(tmp.second > 0 && out[tmp.first][tmp.second-1] == target)
                to_visit.push(make_pair(tmp.first, tmp.second-1));
            if(tmp.second+1 < ny && out[tmp.first][tmp.second+1] == target)
                to_visit.push(make_pair(tmp.first, tmp.second+1));
        }
        
        return out;
    }
};

// DFS Recursive
// class Solution {
// public:
//     void dfs(vector<vector<int>>& image, int x, int y, int target, int color)
//     {
//             image[x][y] = color;
            
//             if(x > 0 && image[x-1][y] == target)
//                 dfs(image,x-1,y,target,color);
//             if(x+1 < image.size() && image[x+1][y] == target)
//                 dfs(image,x+1,y,target,color);
//             if(y > 0 && image[x][y-1] == target)
//                 dfs(image,x,y-1,target,color);
//             if(y+1 < image[0].size() && image[x][y+1] == target)
//                 dfs(image,x,y+1,target,color);
        
//     }
    
//     vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
//         int target = image[sr][sc];
//         if(target == color) return image;
        
//         vector<vector<int>> out(image);
//         dfs(out, sr, sc, target, color);
//         return out;
        
//     }
// };