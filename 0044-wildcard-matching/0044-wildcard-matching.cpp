class Solution {
public:
    bool f(string s,string p,int n,int m,vector<vector<int>> &dp){
        if(n<0 && m<0){
            return true;
        }
        if(m<0){
            return false;
        }
        if(n < 0){
            for(int i = 0;i<=m;i++){
                if(p[i] != '*') return false;
            }
            return true;
        }
        if(dp[n][m] != -1) return dp[n][m];
        if(s[n] == p[m] || p[m] == '?'){
            return dp[n][m] = f(s,p,n-1,m-1,dp);
        }
        else if(p[m] == '*'){
            return dp[n][m] = f(s,p,n,m-1,dp)||f(s,p,n-1,m,dp);
        }
        return dp[n][m] = false;
      
    }
    bool isMatch(string s, string p) {
        int n= s.size();
        int m = p.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        return f(s,p,n-1,m-1,dp);
    }
};