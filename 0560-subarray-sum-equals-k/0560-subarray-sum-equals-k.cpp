class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,vector<int>> mp;
        mp[0] = {0};
        int ans = 0;
        int sum = 0;
        for(int i =0;i<n;i++){
            sum += nums[i];
            mp[sum].push_back(i+1);
        }
        sum = 0;
        for(int i = 0;i<n;i++){
            sum+=nums[i];
            auto &it = mp[sum-k];
            int idx = lower_bound(it.begin(),it.end(),i+1) - it.begin();
            ans += idx;
        }

        return ans;
    }
};