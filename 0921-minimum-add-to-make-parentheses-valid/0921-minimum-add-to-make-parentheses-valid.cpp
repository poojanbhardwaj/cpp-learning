class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        int a = 0,b = 0;
        for(int i = 0;i<n;i++){
            if(s[i] == '('){
                a++;
            }
            else {
                a--;
                if(a<0){
                    a = 0;
                    b++;
                }
            }
        }
        return (a+b);
    }
};