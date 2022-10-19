class Solution {    
public:
    // Find shortest path, given an edge of weight 1 between all stops of a bus
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;

        //Populate adjacency list
        unordered_map<int,vector<int>> adj;
        int n_routes = routes.size();
        for (int i = 0; i < n_routes; ++i)
            for(int j : routes[i])
                adj[j].push_back(i); // attaches each stop to to a route
        
        // BFS from source to end 
        unordered_set<int> visited;
        queue<int> bfs;
        
        visited.insert(source);
        bfs.push(source);
        int stop, bus, to_explore, distance = 0; 
        
        while(!bfs.empty()) {
            to_explore = bfs.size();

            while(to_explore-- > 0) {
                stop = bfs.front(); bfs.pop();
                if(stop == target) return distance;
                
                for (int i : adj[stop]) {
                    for (int j : routes[i]) {
                        if (!visited.count(j)) {
                            visited.insert(j);
                            bfs.push(j);
                        }
                    }
                    routes[i].clear();
                }
            }
            distance++; 
        }
        
        return -1;
    }
};