class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char i : s){
            char t;
            if(i == '(' || i == '{' || i == '[') st.push(i);
            
            else{
            if(!st.empty())  t = st.top();
            else return false;
            if(i == ')' && t == '(' || i == ']' && t == '[' || i == '}' && t == '{'){
                st.pop();
            }
            else return false;
            
            }
        }
        return st.size() == 0;
    }
};