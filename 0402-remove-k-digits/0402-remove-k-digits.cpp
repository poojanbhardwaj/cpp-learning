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
        
        while(!ans.empty() && ans.back() == '0'){
            ans.pop_back();
        }
        reverse(ans.begin(),ans.end());
    return ans.empty() ? "0":ans;
    }

};