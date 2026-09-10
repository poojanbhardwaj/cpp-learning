class Solution {
public:
    int f(vector<pair<int,int>> &players,int i,int prev,vector<vector<int>> &dp){
        if(i == 0) return 0;
        if(dp[i][prev+1] != -1) return dp[i][prev+1];
        if(prev == -1 || players[prev].second >= players[i-1].second){
            return dp[i][prev+1]= max(players[i-1].second + f(players,i-1,i-1,dp),f(players,i-1,prev,dp));
        }
        else{
            return dp[i][prev+1] = f(players,i-1,prev,dp);
        }
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        int maxe = *max_element(scores.begin(),scores.end());
        int mina = *max_element(ages.begin(),ages.end());
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        vector<pair<int,int>> players(n);
        for(int i = 0;i<n;i++){
            players[i]={ages[i],scores[i]};
        }
        sort(players.begin(),players.end());
        
        return f(players,n,-1,dp);   
    }
};