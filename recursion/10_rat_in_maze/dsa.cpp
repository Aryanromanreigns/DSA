class Solution {
public:
    void solve(int i, int j, vector<vector<int>> &a, int n,
               vector<string> &ans, string move,
               vector<vector<int>> &vis,
               int di[], int dj[]) {
        
        // destination reached
        if (i == n - 1 && j == n - 1) {
            ans.push_back(move);
            return;
        }

        string dir = "DLRU";

        for (int ind = 0; ind < 4; ind++) {
            int nexti = i + di[ind];
            int nextj = j + dj[ind];

            if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n &&
                !vis[nexti][nextj] && a[nexti][nextj] == 1) {

                vis[i][j] = 1;  // mark visited

                solve(nexti, nextj, a, n, ans, move + dir[ind], vis, di, dj);

                vis[i][j] = 0;  // backtrack
            }
        }
    }

    vector<string> findPath(vector<vector<int>> &grid, int n) {
        vector<string> ans;

        // edge case: start blocked
        if (grid[0][0] == 0) return ans;

        vector<vector<int>> vis(n, vector<int>(n, 0));

        int di[] = {+1, 0, 0, -1};  // D L R U
        int dj[] = {0, -1, +1, 0};

        solve(0, 0, grid, n, ans, "", vis, di, dj);

        return ans;
    }
};