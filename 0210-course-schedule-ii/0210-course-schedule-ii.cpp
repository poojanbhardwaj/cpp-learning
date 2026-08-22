class Solution {
public:
 bool dfs(int i,
         vector<int>& vis,
         vector<int> adj[],
         vector<int>& path,vector<int> &result){
        vis[i] = 1;
        path[i] =1;
      
        for(auto &it:adj[i]){
            if(!vis[it]){
                if(dfs(it,vis,adj,path,result)) return true;

            }
            else if(path[it]) return true;
        }



        path[i]= 0;
          result.push_back(i);
        return false;
    }
    vector<int> findOrder(int numc, vector<vector<int>>& pre) {
         vector<int> adj[numc];
        for(auto &it:pre){
            adj[it[1]].push_back(it[0]);
        }
        queue<int> q;
        vector<int> indegree(numc, 0);
        for(int i = 0;i<numc;i++){
            for(auto &it:adj[i]){
                indegree[it]++;
            }
        }
        for(int i = 0;i<numc;i++){
            if(indegree[i] == 0) q.push(i);
        }
        vector<int> topo;
        while(!q.empty()){
            int i = q.front();
            q.pop();
            topo.push_back(i);
            for(auto &it:adj[i]){
                indegree[it]--;
                if(indegree[it] == 0)q.push(it);
            }
        }
       
        if(topo.size() != numc) return {};
        return topo;
    
    }
};