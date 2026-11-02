class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        sort(nums.begin(),nums.end());
               int med =
             nums[n/2];
        
        for(int i : nums){
            ans+=abs(i-med);
        }
        return ans;
    }
};