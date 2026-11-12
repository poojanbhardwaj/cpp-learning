class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
           int n = nums.size();
           int ans = 0;
           for(int i = 0;i<n;i++){
                for(int j = i;j<n;j++){
                    bool issort1 = true;
                    bool issort2 = true;

                    for(int k = i;k<j;k++){
                        if(nums[k] >= nums[k+1]){
                            issort1 = false;
                            break;
                        }
                        
                    }       
                      for(int k = i;k<j;k++){
                        if(nums[k] <= nums[k+1]){
                            issort2 = false;
                            break;
                        }
                        
                    
                    }
                    if(issort1 || issort2) ans = max(ans,j-i+1);                
                }
           }
           return ans;
    }
};