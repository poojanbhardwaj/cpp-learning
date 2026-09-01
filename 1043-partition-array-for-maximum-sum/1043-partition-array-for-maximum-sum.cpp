class Solution {
public:
    int f(int i,int k,vector<int> &arr,vector<int> &dp){
        if(i == 0){
            return 0;
        }
        if(dp[i] != -1) return dp[i];
        int ans = 0;
        int maxi = 0;
        
        for(int j = 1;j<=min(k,i);j++){
        
            maxi = max(maxi,arr[i-j]);
            int temp = 0;
            temp = maxi*j+f(i-j,k,arr,dp);
            ans = max(ans,temp);
        }
        return dp[i]  = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1,-1);
        return f(n,k,arr,dp);
    }
};