class Solution {
public:
    bool can(vector<int>&nums,vector<int>&s){
        int n = s.size();
        int st = -1;
        int drop = 0;
        for(int i = 0;i<n;i++){
            if(nums[i] > nums[(i+1)%n]){
                drop++;
                st = (i+1)%n;
            }
        }
        if(drop > 1) return false;
        if(drop == 0) st = 0;
        for(int i = 0;i<n;i++){
            if(s[i] != nums[(st+i)%n]){
                return false;
            }
        }
        return true;
    }
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<int> s = nums;
        sort(s.begin(),s.end());
        for(int i =1;i<=n;i++){
            if(n%i == 0){
                bool ok = true;
                for(int j = 0;j<n;j+=i){
                    vector<int> a(nums.begin()+j,nums.begin() + j+ i);
                    vector<int>b(s.begin() + j,s.begin()+j+i);
                    if(!can(a,b)){
                        ok = false;
                        break;
                    }
                }
                if(ok) ans+=i;
            }
        }
        return ans;
    }
};