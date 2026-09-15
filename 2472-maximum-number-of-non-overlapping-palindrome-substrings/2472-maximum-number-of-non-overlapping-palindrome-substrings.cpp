class Solution {
public:
    bool ispalindrome(string &s,int i,int j){
        while(i<j){
            if(s[i] != s[j]) return false;
            i++;j--;
        }
        return true;
        
    }
    int maxPalindromes(string s, int k) {
        int n = s.size();
        int ans = 0;
        int st = 0;
        for(int j = k-1;j<n;j++){
            for(int i = st;i<=j-k+1;i++){
                
                    if(ispalindrome(s,i,j)){
                        ans++;
                        st = j+1;
                        j = st +k-2;
                        break;

                    }
                
            }
        }
        return ans;
    }
};