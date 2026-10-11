class Solution {
public:
typedef long long ll;
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<ll> ans(n);
        vector<pair<ll,pair<ll,ll>>> arr(n);
        for(int i = 0;i<n;i++){
            arr[i] = {nums1[i],{i,nums2[i]}};
        }
        sort(arr.begin(),arr.end());
        priority_queue<ll,vector<ll>,greater<ll>>pq;
    
        ll sum = 0;
        for(int i = 0;i<n;i++){
            pair<ll,pair<ll,ll>> p= arr[i];
            long a = p.first;
            long ind = p.second.first;
            long long b = p.second.second;
            if(i>0 && arr[i-1].first == a){
                ans[ind] = ans[arr[i-1].second.first];
            }else{
            ans[ind] = sum;}
            sum+=b;
            pq.push(b);
            if(pq.size()>k){
                sum-=pq.top();
                pq.pop();
            }
        }
        return ans;
    }
};