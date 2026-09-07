class Solution {
public:
    int f(string& s,string &t,int i,int j,vector<vector<int>> &dp){
        if(i == 0 && j == 0) return 1;

        else if(j == 0) return 1;
        else if(i==0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        if(s[i-1] == t[j-1]) {
            ans += f(s,t,i-1,j-1,dp) + f(s,t,i-1,j,dp);
        }
        else{
            ans+=f(s,t,i-1,j,dp);
        }
        return dp[i][j] = ans;
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>>dp(n+1,vector<int> (m+1,-1));
        return f(s,t,n,m,dp);
    }
};