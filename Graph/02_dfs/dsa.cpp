    void dfs(int node , int V , vector<int>adj[],vector<int>&ans,int vis[]){
        vis[node] = 1;
        ans.push_back(node);
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it,V,adj,ans,vis);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int>ans;
        int vis[V] ={0};
        dfs(0,V,adj,ans,vis);
        return ans;
     
    }