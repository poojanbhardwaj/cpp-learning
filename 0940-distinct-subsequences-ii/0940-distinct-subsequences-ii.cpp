class Solution {
public:
    int mod = 1e9+7;
    int f(string &s,unordered_map<string,int>&dp,int i,string temp){
        if(i == 0) {
            if(temp.empty()) return 0;
            if(dp.find(temp) != dp.end()) return 0;
            dp[temp] = 1;
            return 1;
        }
      
         
        int pick = f(s,dp,i-1,temp+s[i-1]);
        int dpick = f(s,dp,i-1,temp);
      
        return pick + dpick;
        

    }
    int distinctSubseqII(string s) {
        int n = s.size();
        vector<long long> dp(n+1);
        dp[0] = 1;
        vector<int> seen(26,-1);
        for(int i = 1;i<=n;i++){
            if(seen[s[i-1]-'a'] != -1){
                dp[i] = (dp[i-1]*2LL-dp[seen[s[i-1]-'a']]+mod)%mod;
                 seen[s[i-1] - 'a'] = i-1;
            }
            else{
                dp[i] = dp[i-1]*2LL%mod;
                seen[s[i-1] - 'a'] = i-1;
            }
        }
        return (dp[n]-1+mod)%mod;
    }
};