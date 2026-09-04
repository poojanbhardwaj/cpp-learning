class Solution {
public:
    void f(int i,int end,int sum,int ne,vector<int> &nums,vector<vector<int>> &half){
       
           
           
        
        if(i == end){
            half[ne].push_back(sum);
          return;
        }
      
        
        f(i+1,end,sum+nums[i],ne+1,nums,half);
        f(i+1,end,sum,ne,nums,half);

    }
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int t = n/2;
        vector<vector<int>> left(t+1);
        vector<vector<int>> right(t+1);
        f(0,t,0,0,nums,left);
        f(t,n,0,0,nums,right);
        int ans = INT_MAX;
        int total = 0;
        for(int i : nums) total += i;
        for(int i = 0;i<=t;i++){
            vector<int>& group = right[t-i];
              sort(group.begin(),group.end());
            for(auto ls:left[i]){
                int tar = total/2-ls;
               auto it= lower_bound(group.begin(),group.end(),tar);
                if(it!=group.end()){
                    int su = ls+*it;
                    ans = min(ans,abs(total-2*su));
                }
                if(it!=group.begin()){
                    --it;
                    int su = ls+*it;
                    ans = min(ans,abs(total-2*su));
                }
               
            }
        }
        
return ans;
    }
};