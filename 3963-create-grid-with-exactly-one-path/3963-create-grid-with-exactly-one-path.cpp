class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;
        for(int i = 0;i<m;i++){
            string t = "";
            for(int j = 0;j<n;j++){
                if(i == 0 || j == n-1){
                    t+='.';
                    continue;
                }
                else{
                    t+='#';
                }

                
            }
            ans.push_back(t);

        }
        return ans;
    }
};