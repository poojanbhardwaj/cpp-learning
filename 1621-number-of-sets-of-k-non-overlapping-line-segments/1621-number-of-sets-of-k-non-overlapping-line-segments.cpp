class Solution {
public:
int mod = 1e9+7;
    int f(int i,int k,int n,vector<vector<int>> &dp){
        if(k == 0) return 1;
        if(i == n) return 0;
        if(dp[i][k] != -1) return dp[i][k];
        int skip = f(i+1,k,n,dp)%mod;
        int take = 0;
        for(int j = i+1;j<=n-1;j++){
            take+=f(j,k-1,n,dp)%mod;
        }
        return dp[i][k]=(take+skip)%mod;
    }
    int numberOfSets(int n, int k) {
        vector<vector<int>> dp(n+1,vector<int> (k+1,0));
        vector<int> pref(k+1,0);
        for(int i = 0;i<n;i++) dp[i][0] = 1;
        for(int i = n-1;i>=0;i--){

            for(int j = 1;j<=k;j++){
                int skip = dp[i+1][j]%mod;
                int take = 0;
                
                    take = pref[j-1]%mod;
                
                dp[i][j] = (skip+take)%mod;
            }
            for(int j = 0;j<=k;j++){
                pref[j] = (pref[j] + dp[i][j])%mod;
            }
            
        }
        return dp[0][k]%mod;
    }
};