
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int,int>> q;

        vector<int> drow = {0, 1, 0, -1};
        vector<int> dcol = {1, 0, -1, 0};

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] && grid[i][j] == 0) {

                    bool closed = true;
                    q.push({i, j});
                    vis[i][j] = 1;

                    while(!q.empty()) {
                        int k = q.front().first;
                        int f = q.front().second;
                        q.pop();

                        if(k == 0 || f == 0 || k == n-1 || f == m-1) {
                            closed = false;
                        }

                        for(int t = 0; t < 4; t++) {
                            int nr = k + drow[t];
                            int nc = f + dcol[t];

                            if(nr >= 0 && nc >= 0 &&
                               nr < n && nc < m &&
                               !vis[nr][nc] &&
                               grid[nr][nc] == 0) {

                                q.push({nr, nc});
                                vis[nr][nc] = 1;
                            }
                        }
                    }

                    if(closed) ans++;
                }
            }
        }
        return ans;
    }
};
