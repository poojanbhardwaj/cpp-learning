class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> ans(n,-1);
        int m = nums2.size();
        for(int i = 0;i<n;i++){
            int el = nums1[i];
            for(int j = 0;j<m;j++){
                if(el == nums2[j]){
                    for(int k = j+1;k<m;k++){
                        if(nums2[k] > el){
                            ans[i] = nums2[k];
                            break;
                        }

                    }
                    
                }
            }
        }
        return ans;
    }
};