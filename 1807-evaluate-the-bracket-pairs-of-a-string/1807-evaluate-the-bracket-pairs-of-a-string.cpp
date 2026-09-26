class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string ans = "";
        int n = s.size();
        unordered_map<string,string> mp;
        for(auto&it:knowledge){
            mp[it[0]] = it[1];
        }
        string temp = "";
        int seen = 0;
        for(int i = 0;i<n;i++){
            if(s[i] == '('){
                seen++;
                continue;
            }
            if(seen && s[i] != ')'){
                temp+=s[i];
                continue;
            }
            if(s[i] == ')'){
                seen--;
                if(mp.find(temp) == mp.end()){
                    ans+='?';
                }
                else{
                    ans+=mp[temp];
                }
                temp = "";
                continue;
            }
            

            ans+=s[i];
        }
        return ans;
    }
};