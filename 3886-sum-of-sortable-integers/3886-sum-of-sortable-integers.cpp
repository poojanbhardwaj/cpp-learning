class Solution {
public:
    bool can(vector<int>& a, vector<int>& s, int l, int len) {
        int drop = 0, start = 0;
        for (int t = 0; t < len; t++) {
            if (a[l + t] > a[l + (t + 1) % len]) {
                drop++;
                start = (t + 1) % len;      // offset inside the block
            }
        }
        if (drop > 1) return false;
        for (int t = 0; t < len; t++) {
            if (s[l + t] != a[l + (start + t) % len]) return false;
        }
        return true;
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<int> s = nums;
        sort(s.begin(), s.end());

        for (int k = 1; k <= n; k++) {
            if (n % k) continue;
            bool ok = true;
            for (int j = 0; j < n; j += k) {
                if (!can(nums, s, j, k)) { ok = false; break; }
            }
            if (ok) ans += k;
        }
        return ans;
    }
};