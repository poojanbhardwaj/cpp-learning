class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int ans = 0;
        int maxi = *max_element(nums.begin(),nums.end());
        int mini = *min_element(nums.begin(),nums.end());
        int med = (maxi+mini)/2;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        if(med != nums[n/2]){
                med = nums[n/2];
        }
        for(int i : nums){
            ans+=abs(i-med);
        }
        return ans;
    }
};