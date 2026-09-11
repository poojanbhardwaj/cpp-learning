class Solution {
public:
    void f(vector<int> &digits,unordered_set<int> &ans,vector<int> &used,int idx,int num){
        if(idx == 3){
            if(num%2== 0){
                ans.insert(num);
            }
            return;
        }
        for(int i = 0;i<digits.size();i++){
            if(used[i]) continue;
           
            if(idx == 0 && digits[i] == 0) continue ;
            used[i] = 1;
            f(digits,ans,used,idx+1,num*10+digits[i]);
            used[i] = 0;
        }


    }
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        unordered_set<int> ans;
        vector<int> used(n,0);
         f(digits,ans,used,0,0);
         return ans.size();
    
    }
};