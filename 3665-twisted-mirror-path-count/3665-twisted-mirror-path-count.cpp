class Solution {
public:
int mod = 1e9+7;
    int f(vector<vector<int>>& grid,int i,int j,int dir,vector<vector<vector<int>>> &dp){
        if(i<0 || j < 0) return 0;
        if(i == 0 && j == 0) return 1;
        if(dp[i][j][dir] != -1) return dp[i][j][dir];
        int ans = 0;
        if(grid[i][j] == 0){
            ans += f(grid,i-1,j,0,dp)%mod;
            ans+= f(grid,i,j-1,1,dp)%mod;
        }                         
        if(grid[i][j] == 1){
            if(dir == 0){
                ans+=f(grid,i,j-1,1,dp)%mod;
            }
            else{
                ans+=f(grid,i-1,j,0,dp)%mod;
            }
        }    
        return dp[i][j][dir] = ans;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (m+1,vector<int> (2,-1)));
        return f(grid,n-1,m-1,0,dp)%mod;
    }
};