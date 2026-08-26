class Solution {
public:
    int f(string &s,string &t,int i,int j,vector<vector<int>> &dp){
        
        if(i == s.size() || j==t.size()){
            if(j == t.size()) return 1;
            return 0;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        int ans= 0;
        if(s[i] == t[j]){
            ans+=f(s,t,i+1,j+1,dp) + f(s,t,i+1,j,dp);
        }
        else{
        ans += f(s,t,i+1,j,dp);

        }
        return dp[i][j] = ans;
    }
    int numDistinct(string s, string t) {
        int n= s.size();
        int m = t.size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        return f(s,t,0,0,dp);
    }
};