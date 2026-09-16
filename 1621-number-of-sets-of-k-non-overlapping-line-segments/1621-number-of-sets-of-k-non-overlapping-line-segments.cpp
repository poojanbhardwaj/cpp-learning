class Solution {
public:
    static constexpr int MOD = 1'000'000'007;
    vector<vector<int>> dp;

    int f(int n, int r) {
        if (r == 0) return 1;
        if (r > n) return 0;

        int& ans = dp[n][r];
        if (ans != -1) return ans;

        int take = f(n - 1, r - 1);
        int skip = f(n - 1, r);

        return ans = (take + skip) % MOD;
    }

    int numberOfSets(int n, int k) {
        int positions = n + k - 1;
        int endpoints = 2 * k;

        dp.assign(positions + 1, vector<int>(endpoints + 1, -1));

        return f(positions, endpoints);
    }
};