class Solution {
public:
    int f(int i,int k,vector<int> &arr,vector<int> &dp){
        if(i == 0){
            return 0;
        }
        if(dp[i] != -1) return dp[i];
        int ans = 0;
        int maxi = 0;
        
        for(int j = 1;j<=k;j++){
           
            for(int t = 1;t<=j;t++){
               if(i-t>=0) maxi = max(maxi,arr[i-t]);
            }
            int temp = 0;
            if(i-j>=0)  temp = maxi*j+f(i-j,k,arr,dp);

            
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