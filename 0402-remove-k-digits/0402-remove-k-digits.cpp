class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if(n == k) return "0";
        string ans = "";
        stack<char> st;
        for(int i = 0;i<n;i++){
            while(k>0 && !st.empty() && st.top() - '0' > num[i]-'0'){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k>0){
            st.pop();k--;
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        int i = 0;
        bool seen = true;
        string res = "";
        while(i<ans.size()){
        if(ans[i] == '0' && seen){
            i++;
        }
        else {
            res+=ans[i];
            seen = false;
            i++;
        }
        
    } 
    return res.empty() ? "0":res;
    }

};