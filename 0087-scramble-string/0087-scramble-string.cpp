class Solution {
public:
    bool f(string a,string b,unordered_map<string,bool> &mp){
        if(a.compare(b) == 0){
            return true;
        }
        if(a.size() <= 1) return false;
        string t = a+'#'+b;
        if(mp.find(t) != mp.end()) return mp[t];
        int n = a.size();
        bool sc = false;
        for(int i = 1;i<n;i++){
            if((f(a.substr(0,i),b.substr(n-i,i),mp) && f(a.substr(i,n-i),b.substr(0,n-i),mp))||(f(a.substr(0,i),b.substr(0,i),mp) && f(a.substr(i,n-i),b.substr(i,n-i),mp))){
            sc = true; break;
            }
        }
        return mp[t] = sc;
    }
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if(n != m) return false;
        unordered_map<string,bool> mp;
        if(n == 0 || m == 0) return true;
        return f(s1,s2,mp);
    }
};