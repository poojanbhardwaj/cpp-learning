class Solution {
public:
    int n;
    string s;
    int idx =  0;
    set<string> getUnit(){
        set<string> ans;
       if(s[idx] == '{') {idx++;ans = performUnion();}
       else {
        ans = {string(1,s[idx])};

       }
       idx++;
       return ans;
    }
    set<string>getcon(){
        set<string> ans = {""};
        while(idx < n && (s[idx] == '{' || isalpha(s[idx]))){
            set<string> temp = getUnit();
            set<string>conc;
            for(const string&left : ans){
                for(const string &right: temp){
                    conc.insert(left + right);

                }
            }
            ans = conc;
          
        }
        return ans;
    }
    set<string> performUnion(){
        set<string> ans;
        while(true){
            set<string> temp = getcon();
            
            
            ans.insert(temp.begin(),temp.end());
            if(idx<n && s[idx] == ',') idx++;
            else break;
        }
        return ans;
    }
    vector<string> braceExpansionII(string expression) {
        n = expression.size();
        s = expression;
        idx  = 0;
        set<string> result = performUnion();
        vector<string> ans(result.begin(),result.end());
        return ans;

    }
};