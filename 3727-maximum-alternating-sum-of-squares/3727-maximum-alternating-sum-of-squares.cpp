class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n);
        for(int i= 0;i<n;i++){
            temp[i] =abs(nums[i]);
        }
        sort(temp.begin(),temp.end());
        long long ans = 0;
        int l = 0;
        int r = n-1;
        while(l<=r){
            if(l<r)ans += 1LL*temp[r]*temp[r] - 1LL*temp[l]*temp[l];
            else ans+=1LL*temp[r]*temp[r];
            r--;
            l++;
        }
    return ans;
    }
};