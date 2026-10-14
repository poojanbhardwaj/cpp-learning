class Solution {
public:
    double p(double x,int n){
        if(n == 0) return 1;
        if(n%2 == 0){
            return p(x*x,n/2);
        }
        else{
            return x*p(x*x,n/2);
        }
    }
    double myPow(double x, int n) {
        if(x == 0) return 0;
        double ans = p(x,n);
        return n>=0 ? ans:1/ans;
    }
};