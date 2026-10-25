class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n,vector<int> (m,0));
        queue<pair<int,int>>q;
        vector<int> drow = {0,1,0,-1};
        vector<int> dcol = {1,0,-1,0};
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    ans++;
                    q.push({i,j});
                    vis[i][j] = 1;
                    while(!q.empty()){
                        int k = q.front().first;
                        int f = q.front().second;
                        q.pop();
                        for(int t = 0;t<4;t++){
                            int nr = k+drow[t];
                            int nc =f+dcol[t];
                            if(nr>=0 && nc >=0 && nc < m && nr < n && !vis[nr][nc] && grid[nr][nc] == '1'){
                                q.push({nr,nc});
                                vis[nr][nc] = 1;
                            } 
                        }
                    }
                }
            }
        }
        return ans;

    }
};