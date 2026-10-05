class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();
        int ans = 0;
        int in = 0;
        stack<int> st;
        for(int i=0;i<n;i++){
            if(s[i] == '('){
                in++;
                st.push(i);
            }
            else{

                in--;
                if(i>0 && s[i-1]== '('){
                    ans+=pow(2,in);}
            }
        }
        return ans;
    }
};