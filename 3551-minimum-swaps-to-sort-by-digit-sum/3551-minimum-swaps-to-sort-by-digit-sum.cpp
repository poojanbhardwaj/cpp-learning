class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        vector<pair<int,int>>temp;
        for(int i = 0;i<n;i++){
            int sum = 0;
            int t = nums[i];
            while(t>0){
                sum += t%10;
                t /= 10;
            }
            temp.push_back({sum,nums[i]});
        }
        sort(temp.begin(),temp.end());
        unordered_map<int,int>mp;
        for(int i = 0;i<temp.size();i++){
            mp[temp[i].second] = i;

        }
        for(int i = 0;i<n;i++){
            int j = mp[nums[i]];
            while(mp[nums[i]] != i){
                swap(nums[i],nums[mp[nums[i]]]);
                ans++;
            }
        }
        return ans;
    }
};