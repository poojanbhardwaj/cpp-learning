class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        stack<char>st;
        for(int i = 0;i<s.size();i++){
           
            if(s[i] == ')') st.pop();
            if(!st.empty()) ans+=s[i];
            if(s[i] == '(') st.push(s[i]);
        }
        return ans;
    }
};