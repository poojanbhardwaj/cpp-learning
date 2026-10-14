class Solution {
public:
int mod = 1e9+7;
 int p(long long t,long long n){
      long long ans = 1;
      t = t%mod;
      while(n>0){
        if(n&1){
            ans = ans*t%mod;
        }
        t = t*t%mod;
        n>>=1;
      }
      return ans;
    }
    int countGoodNumbers(long long n) {
       long long evenPositions = n / 2 + n % 2;
        long long oddPositions = n / 2;

        return 1LL*p(5, evenPositions) * p(4, oddPositions) % mod;
    }
};