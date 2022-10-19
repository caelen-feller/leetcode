class Solution {
    vector<vector<int>> graph;
    vector<bool> call_stack;
    vector<bool> taken;
    vector<int> ans;
    int ans_i = 0;
    int n;
    
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        n = numCourses;
        if(n == 1) return {0};

        // Populate dependency graph 
        int p = prerequisites.size();
        graph = vector<vector<int>>(n);
        for(int i = 0; i < p; i++) graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        
        taken = vector<bool>(n);
        call_stack = vector<bool>(n);
        ans = vector<int>(n);
        for(int i = 0; i < n; i++) { // Search each course (if not reached), add to ordering
            if(!taken[i] and dfs(i)) return {}; // Impossible if a dependency cycle is found
        }
        return ans;
    }
    
    bool dfs(int course) {
        // cout << "Processing " << course << endl; 
        taken[course] = true;
        call_stack[course] = true;
        int d = graph[course].size();
        for(int i = 0; i < d; ++i) {
            if(!taken[graph[course][i]] and dfs(graph[course][i])) return true;
            else if(call_stack[graph[course][i]]) return true;
        }
        
        ans[ans_i++] = course;
        call_stack[course] = false;
        return false;
    }
};