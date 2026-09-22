class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        vector<int> st;

        for(int x : nums) {
            bool alive = true;

            while(alive && !st.empty() && st.back() > 0 && x < 0) {

                if(st.back() < -x) {
                    st.pop_back();
                }
                else if(st.back() == -x) {
                    st.pop_back();
                    alive = false;
                }
                else {
                    alive = false;
                }
            }

            if(alive) {
                st.push_back(x);
            }
        }

        return st;
    }
};