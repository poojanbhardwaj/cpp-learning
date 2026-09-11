class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int n =nums.size();
        unordered_map<int,int> mp;

        for(int i = 0;i<=n-2;i++){
            int sum = 0;
            for(int j = 0;j<2;j++){
                sum+=nums[i+j];
            }
           if(mp.count(sum) != 0){ return true;}
           mp[sum]++;
        }
        return false;
    }
};