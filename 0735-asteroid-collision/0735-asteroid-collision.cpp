class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> ans;
        for(int i = n-1;i>=0;i--){
            bool alive =true;
            while(!st.empty() && st.top() < 0 && nums[i]>0){
                if(nums[i] > abs(st.top())){
                    st.pop();
                }
                else if(nums[i] == abs(st.top())){
                    st.pop();
                    alive = false;
                    break;
                }
                else{
                    alive = false;
                    break;
                }

            }
            if(alive) st.push(nums[i]);
        }
       
        while(!st.empty()){ans.push_back(st.top());st.pop();}
        
        return ans;
    }
};