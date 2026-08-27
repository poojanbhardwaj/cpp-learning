class Solution {
public:
    bool f(string &s,string &p,string &t,int i,int j,vector<vector<int>> &dp){
        
        
        if(i == 0){
            for(int k = 0;k<j;k++){
                if(p[k] != t[k]) return false;
            }
            return true;
        }
         if(j == 0){
            for(int k = 0;k<i;k++){
                if(s[k] != t[k]) return false;
            }
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];
        bool ans = false;
        if(s[i-1] == t[i+j-1]){
           ans = f(s,p,t,i-1,j,dp);
        }
        if(p[j-1] == t[i+j-1]) ans = ans||f(s,p,t,i,j-1,dp);
        return dp[i][j] = ans;

    }
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
      
        if(n+m != s3.size()) return false;
        return f(s1,s2,s3,n,m,dp);
    }
};