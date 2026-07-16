class Solution {
public:
    int gcd(int a,int b)
        {
            int rem;
            while(b!=0)
                {
                    rem=a%b;
                    a=b;
                    b=rem;
                }
            return a;    
        }
    long long gcdSum(vector<int>& nums) {
        int maxPrefix=nums[0],n=nums.size();
        for(int i=0;i<n;i++)
            {
                maxPrefix=max(maxPrefix,nums[i]);
                nums[i]=gcd(maxPrefix,nums[i]);
            }
        sort(nums.begin(),nums.end());
        int st=0,end=n-1;
        long long sum=0;
        while(st<end)
            {
                sum+=gcd(nums[st],nums[end]);
                st++,end--;
            }
        return sum;    

        
        
    }
};