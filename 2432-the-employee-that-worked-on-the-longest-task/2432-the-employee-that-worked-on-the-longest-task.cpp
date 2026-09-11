class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int ans = logs[0][0];
        int s = logs.size();
        int time = logs[0][1];

        for(int i = 1;i<s;i++){
            int t = logs[i][1]-logs[i-1][1];
            if(t >= time){
                if(t == time)ans = min(ans,logs[i][0]);
               else ans = logs[i][0];
               time =t;
            }
        }
        return ans;
    }
};