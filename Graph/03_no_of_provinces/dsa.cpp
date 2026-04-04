class Solution {
public:
    void dfs(vector<int>adjlist[],int v , vector<int>&vis,int node){
        vis[node] = 1;
        for(auto it : adjlist[node]){
            if(!vis[it]){
                dfs(adjlist,v,vis,it);
            }
        }

    }
    int findCircleNum(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int cnt = 0;

        //mat to ajlist
        vector<int>adjlist[n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m ;j++){
                if(mat[i][j] == 1 && i!= j){
                adjlist[i].push_back(j);
                adjlist[j].push_back(i);
                }
            }
        }

        vector<int>vis(n,0);
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                cnt++;
                dfs(adjlist,n,vis,i);
            }
        }
        return cnt;
        
    }
};