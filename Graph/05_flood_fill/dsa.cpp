class Solution {
public:
    void dfs(vector<vector<int>>& ans, int sr, int sc, int clr, int iniclr, vector<vector<int>>& vis){
        int n = ans.size();
        int m = ans[0].size();

        vis[sr][sc] = 1;
        ans[sr][sc] = clr;

        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};

        for(int i = 0; i < 4; i++){
            int nrow = sr + delrow[i];
            int ncol = sc + delcol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
               !vis[nrow][ncol] && ans[nrow][ncol] == iniclr){
                dfs(ans, nrow, ncol, clr, iniclr, vis);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> ans = image;

        int iniclr = image[sr][sc];

        if(iniclr == color) return image;  

        dfs(ans, sr, sc, color, iniclr, vis);

        return ans;
    }
};