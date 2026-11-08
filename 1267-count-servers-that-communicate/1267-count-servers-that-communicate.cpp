class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<int> rowVis(n, 0);
        vector<int> colVis(m, 0);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                int t = 0;

                if(grid[i][j] == 1 && !vis[i][j]) {

                    queue<pair<int,int>> q;
                    q.push({i,j});
                    vis[i][j] = 1;

                    while(!q.empty()) {
                        int r = q.front().first;
                        int c = q.front().second;
                        q.pop();

                        t++;

                        // Check entire row
                        if(!rowVis[r]) {
                            rowVis[r] = 1;

                            for(int k = 0; k < m; k++) {
                                if(grid[r][k] == 1 && !vis[r][k]) {
                                    q.push({r,k});
                                    vis[r][k] = 1;
                                }
                            }
                        }

                        // Check entire column
                        if(!colVis[c]) {
                            colVis[c] = 1;

                            for(int k = 0; k < n; k++) {
                                if(grid[k][c] == 1 && !vis[k][c]) {
                                    q.push({k,c});
                                    vis[k][c] = 1;
                                }
                            }
                        }
                    }
                }

                if(t > 1) ans += t;
            }
        }

        return ans;
    }
};