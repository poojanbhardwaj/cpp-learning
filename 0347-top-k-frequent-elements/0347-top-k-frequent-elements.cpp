class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int i:nums){
            mp[i]++;
        }
        vector<vector<int>> bucket(n+1);
        for(auto &it:mp){
            bucket[it.second].push_back(it.first);
        }
        for(int i = n;i>=0;i--){
            if(bucket[i].size() == 0) continue;
            while(bucket[i].size() > 0 && k>0){
                ans.push_back(bucket[i].back());
                bucket[i].pop_back();
                k--;
            }
        }
        return ans;
    }
};