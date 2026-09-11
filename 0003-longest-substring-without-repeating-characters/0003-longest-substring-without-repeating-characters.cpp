class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int ans = 0;
        unordered_map<char,int> seen;
        int i = 0;
        int j = 0;
        while(j<n){
            seen[s[j]]++;
            while(seen[s[j]]>1){
                
                seen[s[i]]--;
                i++;
                if(seen[s[i]] == 0) seen.erase(s[i]);

            }
            ans = max(ans,j-i+1);
            j++;
        }
    
        return ans;
    }
};