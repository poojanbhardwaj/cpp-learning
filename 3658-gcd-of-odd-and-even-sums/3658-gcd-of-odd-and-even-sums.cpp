class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int so = (n*n);
        int se = (n)*(n+1);
       
          return __gcd(so,se);
    }
};