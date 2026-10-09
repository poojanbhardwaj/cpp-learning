class Solution {
public:
    int minInsertions(string s) {
        int  n = s.size();
        stack<int>st;
        int ans = 0;
        int l = 0;
        while(l<n){
            if(s[l] == '('){
                st.push(s[l]);
                l++;
            }
            else{
                if(st.empty()){
                    if(l<n-1 && s[l] == s[l+1]){
                        ans+=1;
                        l+=2;

                    }
                    else if(l<n-1 && s[l] != s[l+1]){
                        ans+=2;
                        l++;
                    }
                    else if(l == n-1){
                        ans+=2;
                        l++;
                    }
                }
                else{
                    if(l<n-1 && s[l]== s[l+1]){
                        st.pop();
                        l+=2;
                    }
                    else if(l<n-1 && s[l] != s[l+1]){
                        ans+=1;
                        st.pop();
                        l++;
                    }
                    else if(l == n-1){
                        ans+=1;
                        st.pop();
                        l++;
                    }

                }
            }
        }
     
        return ans+2*st.size();
    }
};