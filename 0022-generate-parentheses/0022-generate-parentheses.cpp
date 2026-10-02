class Solution {
public:
    bool valid(string &s){
        stack<char>st;
        for(char&i:s){
            if(i == '(') {st.push(i);continue;}

            if(!st.empty() && st.top() == '(' && i == ')'){
                st.pop();
               
            }
            else return false;

        }
        return true;
    }
    void generate(int n,vector<string> &ans,int count,string s){
        if(n == 0){
           
                if(valid(s)) ans.push_back(s);
                
            
            return;
        }
        if(count<n)generate(n,ans,count+1,s+'(');
        if(count>=0)generate(n-1,ans,count-1,s+')');

    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int count = 0;
        string s = "";
        generate(n,ans,count,s);
        return ans;
    }
};