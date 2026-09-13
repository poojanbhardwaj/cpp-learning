class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int m = img1[0].size();
        map<pair<int,int>,int> seen2;
        vector<pair<int,int>> n1,n2;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(img1[i][j] == 1) {n1.push_back({i,j});}
                if(img2[i][j] == 1) {
                     n2.push_back({i,j});
                }
            }
        }
        int ans = 0;

        int a = n1.size();
        int b = n2.size();
        for(int i = 0;i<a;i++){
            auto &pair1 = n1[i];
            for(int j = 0;j<b;j++){
                auto &pair2 = n2[j];
                int x = (pair2.first - pair1.first);
                int y = (pair2.second - pair1.second);
                seen2[{x,y}]++;


                
                    
                  
                
                
            }
                

        }
        for(auto &it:seen2) ans = max(ans,it.second);      
        return ans;
      }
};