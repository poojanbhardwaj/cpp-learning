class Solution {
public:
    bool f(int i,int j,vector<vector<char>> &grid,int to,vector<vector<vector<int>>>&dp){
        if(i == 1 && j == 1){
            return to==0;
        }
        if(to<0) return false;
        if(dp[i][j][to]!=-1) return dp[i][j][to];
        bool take = false;
        if(i > 1){
            take = f(i-1,j,grid,to+(grid[i-2][j-1] == ')'?1:-1),dp);
        }
        bool takel = false;
        if(j>1){

            takel = f(i,j-1,grid,to+(grid[i-1][j-2] == ')' ? 1:-1),dp);
        }
        return dp[i][j][to]=take||takel;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>> (m+1,vector<int> (m+n+2,-1)));
        return f(n,m,grid,grid[n-1][m-1] == ')'?1:-1,dp);
    }
};