class Solution {
public:
    static constexpr int MOD = 1'000'000'007;

    vector<vector<int>> dp;
    vector<vector<int>> prefixDP;

    // f(n, k): ways to create k segments using n points
    int f(int n, int k) {
        if (k == 0)
            return 1;

        if (n < k + 1)
            return 0;

        int& answer = dp[n][k];

        if (answer != -1)
            return answer;

        // No segment ends at point n-1
        long long notEnd = f(n - 1, k);

        // A segment ends at n-1
        long long end = prefix(n - 1, k - 1);

        return answer = (notEnd + end) % MOD;
    }

    // f(1,k) + f(2,k) + ... + f(n,k)
    int prefix(int n, int k) {
        if (n <= 0)
            return 0;

        int& answer = prefixDP[n][k];

        if (answer != -1)
            return answer;

        return answer = (
            static_cast<long long>(prefix(n - 1, k)) +
            f(n, k)
        ) % MOD;
    }

    int numberOfSets(int n, int k) {
        dp.assign(n + 1, vector<int>(k + 1, -1));
        prefixDP.assign(n + 1, vector<int>(k + 1, -1));

        return f(n, k);
    }
};