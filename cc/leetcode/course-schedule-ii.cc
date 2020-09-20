// O(n) time | O(n) space
// topological sort
class Solution {
    vector<int> res;
    vector<vector<int>> graph;
    
    bool dfs(int u, vector<bool> &vis, vector<bool> &visiting){
        if(visiting[u] == true)
            return false;
        visiting[u] = true;
        for(int v: graph[u])
            if(!vis[v])
                if(dfs(v, vis, visiting) == false)
                    return false;
        
        res.push_back(u);
        visiting[u] = false;
        vis[u] = true;
        return true;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        graph.resize(numCourses);
        vector<bool> vis(numCourses, false), visiting(numCourses, false);
        for(auto it: prerequisites)
            graph[it[1]].push_back(it[0]);
        
        for(int i = 0; i < numCourses; i++)
            if(!vis[i])
                if(dfs(i,vis, visiting) == false)
                    return {};
        reverse(res.begin(), res.end());
        return res;
        
    }
};

// O(n) time | O(n) space
// kahn's algorithm
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res, indegree(numCourses, 0);
        vector<vector<int>> graph(numCourses);
        for(auto it: prerequisites){
            graph[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
           queue<int> que;
        for(int i = 0; i < numCourses; i++)
            if(indegree[i] == 0)
                que.push(i);
        while(!que.empty()){
            int u = que.front();
            que.pop();
            res.push_back(u);
            for(int v: graph[u])
                if(--indegree[v] == 0)
                    que.push(v);
        }
        if(res.size() == numCourses)
            return res;
        else
            return {};
    }
};