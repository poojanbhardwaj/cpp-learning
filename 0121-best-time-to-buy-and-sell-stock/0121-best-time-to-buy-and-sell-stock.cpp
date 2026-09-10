class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int buy = INT_MAX;
        for(int p : prices){
            buy = min(buy,p);
            ans = max(ans,p-buy);
        }
        return ans;
    }
};