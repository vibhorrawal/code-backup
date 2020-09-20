class Solution {
    bool dfs(vector<vector<int>>& graph, vector<int> &visited, vector<int> &visiting, int u){      
        if(visited[u])
            return false;
        if(visiting[u])
            return true;
        
        visiting[u] = true;
        for(int v: graph[u]){
            if(!visited[v]){
                if(dfs(graph, visited, visiting, v) == true)
                    return true;
            }
        }
        visited[u] = true;
        visiting[u] = false;
        return false;
    }
    bool detectCycle(int numCourses, vector<vector<int>>& prerequisites){
        vector<int> visited(numCourses, false), visiting(numCourses, false);
        vector<vector<int>> graph(numCourses);
        
        for(auto it: prerequisites){
            graph[it[0]].push_back(it[1]);
        }
        for(int i = 0; i < numCourses; i++){
            if(!visited[i]){
                if(dfs(graph, visited, visiting, i) == true)
                    return true;
            }
        }
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // detect cycle using visited and visiting
        return !detectCycle(numCourses,prerequisites);
    }
};

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> graph(numCourses);
        // kahn's algorithm
        for(auto it: prerequisites){
            graph[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        queue<int> que;
        for(int i = 0; i < numCourses; i++)
            if(indegree[i] == 0)
                que.push(i);
        int count = 0;
        while(!que.empty()){
            int it = que.front();
            que.pop();
            count++;
            for(int v: graph[it]){
                if(--indegree[v] == 0)
                    que.push(v);
            }
        }
        return count == numCourses;
    }
};