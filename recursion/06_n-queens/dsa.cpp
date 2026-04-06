class Solution {
public:
    bool issafe(int row , int col ,int n , vector<string>temp){
        int duprow = row ;
        int dupcol = col;
        //upper diagonal
        while(row >= 0 && col >= 0){
            if(temp[row][col] == 'Q') return false;
            row--;
            col--;
        }
        row =  duprow;
        col = dupcol;
        //left diagonal
        while(col >= 0){
            if(temp[row][col] == 'Q') return false;
            col--;
        }

        row = duprow;
        col =dupcol;
        //lower diagonal
        while(row < n && col >= 0){
            if(temp[row][col] == 'Q') return false;
            row++;
            col--;
        }
        return true;
    }
    void solve(int col , int &n , vector<vector<string>>& ans,vector<string>&temp){
        if(col == n){
            ans.push_back(temp);
            return;
        }

        for(int row = 0;row < n; row++){
            if(issafe(row,col,n,temp)==true){
                temp[row][col] = 'Q';
                solve(col+1,n,ans,temp);
                //we want multiple answer so we check another possible
                temp[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        // vector<string>temp(n);
        // string s(n,'.');
        // for(int i = 0 ; i < n ; i++){
        //     temp[i] = s;
        // }
        vector<string> temp(n, string(n, '.'));

        solve(0,n,ans,temp);
        return ans;
        
    }
};












class Solution {
public:
    void solve(int col ,int n , vector<vector<string>>&ans,vector<string>&temp,
    vector<int>&leftrow,vector<int>&lowerdiagonal,vector<int>&upperdiagonal){
        if(col == n){
            ans.push_back(temp);
            return ;
        }

        for(int row = 0; row < n ; row++){
            if(leftrow[row] == 0 &&  lowerdiagonal[row+col] == 0 && 
            upperdiagonal[n-1 + col - row] == 0)
            {
                temp[row][col] = 'Q';
                leftrow[row] = 1;
                lowerdiagonal[row+col] = 1;
                upperdiagonal[n-1 + col - row] = 1;
                solve(col+1,n,ans,temp,leftrow,lowerdiagonal,upperdiagonal);
                temp[row][col] ='.';
                leftrow[row] = 0;
                lowerdiagonal[row+col] = 0;
                upperdiagonal[n-1 + col-row] = 0;


            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>temp(n);
        string s(n , '.');
        for(int i = 0; i < n ; i++){
            temp[i] = s;
        }
        vector<int>leftrow(n,0);
        vector<int>lowerdiagonal(2*n-1,0);
        vector<int>upperdiagonal(2*n-1,0);
        solve(0,n,ans,temp,leftrow,lowerdiagonal,upperdiagonal);
        return ans;
        
    }
};
