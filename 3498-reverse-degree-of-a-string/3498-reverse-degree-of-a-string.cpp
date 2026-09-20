class Solution {
public:
    int reverseDegree(string s) {
        long long ans = 0;
        int idx = 1;
        for(char i : s){
            ans += ('a' - i + 26) * idx;
            idx++;
        }
        return (int)ans;
    }
};