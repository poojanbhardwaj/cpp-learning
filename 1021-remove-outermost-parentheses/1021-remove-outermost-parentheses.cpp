class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        stack<char>st;
        for(int i = 0;i<s.size();i++){
            if(s[i] == '(') st.push(s[i]);
            else{
                if(!st.empty()){
                    if(st.size() > 1) ans+=')';
                    st.pop();
                }
            }
            if(st.size() > 1 && s[i] == '(') ans+=s[i];

           
        }
        return ans;
    }
};