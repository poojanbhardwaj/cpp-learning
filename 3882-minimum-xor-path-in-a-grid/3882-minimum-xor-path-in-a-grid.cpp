class Solution {
public:
    int f(vector<vector<int>>& grid, int i, int j, int cur,
          vector<vector<vector<int>>>& dp) {

        if(i == 0 && j == 0)
            return cur ^ grid[i][j];

        if(dp[i][j][cur] != -1)
            return dp[i][j][cur];

        int newCur = cur ^ grid[i][j];

        int up = INT_MAX;
        if(i > 0)
            up = f(grid, i-1, j, newCur, dp);

        int l = INT_MAX;
        if(j > 0)
            l = f(grid, i, j-1, newCur, dp);

        return dp[i][j][cur] = min(up, l);
    }

    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(
                m, vector<int>(1024, -1)
            )
        );

        return f(grid, n-1, m-1, 0, dp);
    }
};