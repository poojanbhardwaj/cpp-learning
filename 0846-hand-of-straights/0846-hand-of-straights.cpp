class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize != 0) return false;
        

        map<int,int>mp;
        for(auto i:hand) mp[i]++;
        while(!mp.empty()){
            auto it = mp.begin()->first;
            for(int i = 0;i<groupSize;i++){
                if(mp[it+i] == 0) return false;
                mp[it+i]--;
                if(mp[it+i] ==  0) mp.erase(it+i);
            }
        }
        return true;
    }
};