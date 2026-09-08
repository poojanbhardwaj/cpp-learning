class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxs=0;
        int mins =INT_MAX;
        for(int num:prices){
            
            mins=min(mins,num);
            maxs=max(num - mins,maxs);
        }
        return maxs;    }
};