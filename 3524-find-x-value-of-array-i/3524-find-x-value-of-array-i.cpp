class Solution {
public:
   long long f(vector<int>& nums, int i, long long r, int k, int p,vector<vector<long long>> &dp) {
    if(i == nums.size())
        return 0;
    if(dp[r][i] != -1) return dp[r][i];
    long long ore = r;
    r = (r * (nums[i] % k)) % k;

    long long ans = 0;

    if(r == p)
        ans++;

    ans += f(nums, i + 1, r, k, p,dp);

    return dp[ore][i] = ans;
}
   vector<long long> resultArray(vector<int>& nums, int k) {
    int n = nums.size();

    vector<long long> ans(k, 0);
    for(int p = 0; p < k; p++) {
    vector<vector<long long>> dp(k+1,vector<long long>(n+1,-1));

        for(int start = 0; start < n; start++) {

            ans[p] += f(nums, start, 1, k, p,dp);
        }
    }

    return ans;
}
};