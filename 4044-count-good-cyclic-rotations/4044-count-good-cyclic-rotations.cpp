class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        vector<int> lh(n/2,0),rh(n/2,0);
        int ans = 0;
        int m = n/2;
        long long leftsum = 0;
        long long total = 0;
        for(int i : nums) total += i;
        for(int i = 0;i<m;i++) leftsum+=nums[i];

        for(int i = 0;i<n;i++){
            long long r = total-leftsum;
            if(leftsum > r) ans++;
            leftsum-=nums[i%n];
            leftsum += nums[(i+m)%n];
        }
        return ans;
    }
};