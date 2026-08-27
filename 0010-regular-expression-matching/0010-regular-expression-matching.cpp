class Solution {
public:
    bool f(string &s,string &p,int i,int j,vector<vector<int>> &dp){
        if(i == 0 && j == 0) return true;
        if(j == 0) return false;
        if(i==0){
            for(int k = 0;k<j;k++){
                if(p[k] != '*') {
                    if(k+1>=j){
                        return false;
                    }
                    if(p[k+1] != '*') return false;
                }
            }
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i-1] == p[j-1] || p[j-1] == '.'){
            return dp[i][j] = f(s,p,i-1,j-1,dp);
        }
        bool ans = false;
        if(p[j-1]=='*'){
            if((p[j-2] == s[i-1] || p[j-2]=='.'))ans = f(s,p,i-1,j,dp);
           return dp[i][j] = ans||f(s,p,i,j-2,dp); 
           
        }
        return dp[i][j] = false;
    } 
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        return f(s,p,n,m,dp);
    }
};