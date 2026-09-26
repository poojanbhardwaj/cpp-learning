class Solution {
public:
    int trap(vector<int>& arr) {
        int ans=  0;
        int n = arr.size();
        int l = 0,r = n-1;
        int lm = 0,rm = 0;
        while(l<r){
            if(arr[l] <= arr[r]){
                if(arr[l] < lm){
                    ans+=lm-arr[l];
                }
                else lm = arr[l];
                l++;
            }
            else{
                if(arr[r] <rm){
                    ans+=rm-arr[r];

                }
                else{
                    rm = arr[r];
                }
                r--;
            }
        }
        return ans;
    }
};