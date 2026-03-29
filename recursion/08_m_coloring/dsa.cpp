class Solution{
public:
    bool issafe(int node,int col ,vector<vector<int> >& edges , int clr[] ,int n){
        for(int i = 0; i < n;i++){
            if(i!=node && edges[i][node] == 1 && clr[i] == col){
                return false;
            }
        }return true;
    }
    bool solve(int node,vector<vector<int> >& edges , int clr[], int m, int n){
        if(node == n){
            return true;
        }
        for(int i = 1; i <= m ;i++){
            if(issafe(node,i,edges,clr,n)){
                clr[node] = i;
                if(solve(node+1,edges,clr,m,n))return true;
                clr[node] = 0;
            }
        }
        return false;
    }
    bool graphColoring(vector<vector<int> >& edges, int m, int n) {
        int clr[n] = {0};
        if(solve(0,edges,clr,m,n))return true;
        return false;
    	
    }
};