class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> mp(nums.begin(), nums.end());
        int ans = k;
        while (mp.count(ans)) {
            ans += k;
        }
        return ans;
    }
};