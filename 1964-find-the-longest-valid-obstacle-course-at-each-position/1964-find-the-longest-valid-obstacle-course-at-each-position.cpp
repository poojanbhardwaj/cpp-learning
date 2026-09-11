class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> ans(n);
        vector<int> temp;
        temp.push_back(obstacles[0]);
        ans[0] =1;
        for(int i = 1;i<n;i++){
            if(temp.back() <= obstacles[i]) {temp.push_back(obstacles[i]);ans[i] =temp.size();}
            else{
                int idx = upper_bound(temp.begin(),temp.end(),obstacles[i]) - temp.begin();
                temp[idx]= obstacles[i];
                ans[i] = idx+1;

            }
        }
        return ans;
    }
};