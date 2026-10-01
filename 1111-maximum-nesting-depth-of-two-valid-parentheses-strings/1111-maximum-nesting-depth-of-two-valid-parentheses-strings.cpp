class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        stack<int> st;
        vector<int>ans(n,1);
        int depth = 0;
        int md = 0;
        for(char &i:seq){
            if(i == '('){
                depth++;
                md = max(md,depth);
            }
            else depth--;
        }
        int t = md/2;
        for(int i = 0;i<n;i++){
            if(!st.empty() && seq[st.top()] == '(' && seq[i] == ')' &&  depth<=t){
                ans[st.top()] = 0;
                st.pop();
                
                ans[i] = 0;
            }
            if(seq[i] == '(') {
                depth++;
                if(depth<=t) st.push(i);
            }
            else depth--;
        }
        return ans;        
    }
};