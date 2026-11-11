class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans = 0;
        int frst = min(need1,need2);
        int no = need1-min(need1,need2);
        int ns = need2-min(need2,need1);
        ans+=frst*1LL*min(costBoth,cost1+cost2);
        ans+=no*1LL*min(costBoth,cost1);
        ans+=ns*1LL*min(costBoth,cost2);
        return ans;
    }
};