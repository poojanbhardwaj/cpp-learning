class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans ;
        if(num*9 < sum)return "";
        int d = sum/9; int r = sum%9;
        while(d > 0){
            ans+='9';
            sum -= 9;
            d--;
            num--;
        }
        if(r) {ans+= '0' + r;
        sum -= r;
        num--;}
        while(num > 0) {
            ans+='0';
            num--;
        }
        


        return ans;
    }
};