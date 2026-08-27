class Solution {
public:
    // bool f(string &s,string &p,string &t,int i,int j,vector<vector<int>> &dp){
        
        
    //     if(i == 0){
    //         for(int k = 0;k<j;k++){
    //             if(p[k] != t[k]) return false;
    //         }
    //         return true;
    //     }
    //      if(j == 0){
    //         for(int k = 0;k<i;k++){
    //             if(s[k] != t[k]) return false;
    //         }
    //         return true;
    //     }
    //     if(dp[i][j] != -1) return dp[i][j];
    //     bool ans = false;
    //     if(s[i-1] == t[i+j-1]){
    //        ans = f(s,p,t,i-1,j,dp);
    //     }
    //     if(p[j-1] == t[i+j-1]) ans = ans||f(s,p,t,i,j-1,dp);
    //     return dp[i][j] = ans;

    // }
    bool isInterleave(string s, string p, string t) {
        int n = s.size();
        int m = p.size();
        
        if(n+m != t.size()) return false;
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        dp[0][0] = true;
        for(int i = 1;i<=n;i++){
            
                if(s[i-1] == t[i-1] && dp[i-1][0]) dp[i][0]= true;
            
        }
        for(int j = 1;j<=m;j++){
            if(p[j-1] == t[j-1] && dp[0][j-1])dp[0][j] = true;
        }
        
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                bool ans = false;
                if(s[i-1] == t[i+j-1]) {
                   ans = dp[i-1][j];
                }
                if(p[j-1] == t[i+j-1]){
                    ans = ans||dp[i][j-1];
                }
                dp[i][j] = ans;
            }
        }
        return dp[n][m];
    }
};