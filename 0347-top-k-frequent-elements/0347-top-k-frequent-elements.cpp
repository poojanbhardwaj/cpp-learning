class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int i:nums){
            mp[i]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto &it:mp){
            pq.push({it.second,it.first});

        }
        while(!pq.empty() && k>0){
            auto &t = pq.top();
            int i = t.second;
            pq.pop();
            ans.push_back(i);
            k--;
        }
        return ans;
    }
};