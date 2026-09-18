class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> start(26,-1),end(26),isvalid(26,1);
        for(int i = 0;i<n;i++){
             if(start[s[i] - 'a'] == -1){
                start[s[i] - 'a'] = i;
             }
             end[s[i]-'a'] = i;
        }
        for(int c=0;c<26;c++){
            int ind = start[c];
            if(ind == -1) continue;
            for(int i =ind;i<=end[c];i++){
                if(start[s[i] - 'a'] < ind){
                    isvalid[c] = false;
                }
                end[c] = max(end[c],end[s[i]-'a']);
            }
        }
        int lastind = INT_MAX/2;
        vector<string>result;
        for(int i = n-1;i>=0;i--){
            
            if(!isvalid[s[i]-'a']) continue;
            
            if(i == start[s[i] - 'a'] && lastind > end[s[i]-'a']){
                result.push_back(s.substr(i,end[s[i]-'a'] - i+1));
                lastind = i;
            }
            
        }

return result;
    }
};