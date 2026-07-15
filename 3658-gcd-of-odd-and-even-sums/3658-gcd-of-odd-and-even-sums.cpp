class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int so = (n*n);
        int se = (n)*(n+1);
        int ans = 1;
        for(int i = min(so,se);i>0;i--){
            if(so%i == 0 && se%i == 0) return i;
        }
        return 0;
    }
};