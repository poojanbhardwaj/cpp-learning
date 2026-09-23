class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
      int n = nums.size();
        
        int ans = INT_MIN;
        int sum = 0;
        for(int i =0;i<n;i++){
            sum += nums[i];

        }

        int k = sum - x;
        if(k < 0) return -1;

        sum = 0;
        int i = 0;
        int j = 0;
        while(j<n){
            sum+=nums[j];
            while(sum > k && i < n){
                sum -= nums[i];
                i++;
            }
            if(sum == k){
                ans = max(ans,j-i+1);

            }
            j++;
        }
        return (ans == INT_MIN) ? -1: n - ans;
    }
};