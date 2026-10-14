class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        if(num*9 < sum)return "";
        int digit = 0;
        while(num>0&& sum>0){
            ans+=to_string(min(9,sum));
            sum-= min(9,sum);
            num--;
        }

        while(num > 0){
            ans+='0';
            num--;        }
            return ans;
    }
};