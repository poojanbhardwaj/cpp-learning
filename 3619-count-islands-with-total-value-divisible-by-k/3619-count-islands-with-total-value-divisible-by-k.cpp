class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int ans = 0;
        int drow[]={0,-1,0,1};
        int dcol[]={-1,0,1,0};
        queue<pair<int,int>> q;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(!vis[i][j] && grid[i][j]>0){
                long long sum = grid[i][j];

                    vis[i][j] = 1;
                    q.push({i,j});
                    while(!q.empty()){
                        int r = q.front().first;
                        int c = q.front().second;
                        q.pop();
                        for(int k = 0;k<4;k++){
                            int nr = r+drow[k];
                            int nc = c+dcol[k];
                            if(nr >= 0 && nr < n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc] > 0){
                                sum+=grid[nr][nc];
                                vis[nr][nc] = 1;
                                q.push({nr,nc});
                            }
                        }
                    }
                if(sum > 0 && sum%k == 0) ans++;

                }
            }
        }
        return ans;
    }
};