class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> st;
        bool push = false;

        for (int i = 0; i < n; i++) {
            if (st.empty() && (s[i] == ')' || s[i] == '}' || s[i] == ']')) {
                return false;
            }
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
                continue;
            }
            if (!st.empty()) {
                if ((st.top() == '(' && s[i] == ')')) {
                    st.pop();
                    continue;
                }

               else if (st.top() == '[' && s[i] == ']') {
                    st.pop();
                    continue;

                }

                else if (st.top() == '{' && s[i] == '}') {
                    st.pop();
                    continue;

                } else
                    return false;
            }
        }
        if (!st.empty())
            return false;
        return true;
    }
};