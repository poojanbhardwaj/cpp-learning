class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        int count = 0;
        stack<char> st1,st2;
        for(int i = 0;i<n;i++){
            if(s[i] == '('){
                st1.push(s[i]);
                st2.push(s[i]);
            }
            else if(s[i] == '*'){
                st1.push('(');
                if(!st2.empty()){
                    st2.pop();
                }
                
            }
            else{
                if(st1.empty() && st2.empty()) return false;
                if(!st1.empty()){
                    st1.pop();
                }
                if(!st2.empty()) st2.pop();
            }
        }
        return st1.empty()||st2.empty();
    }
};