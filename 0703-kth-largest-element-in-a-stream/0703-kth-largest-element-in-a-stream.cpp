class KthLargest {
public:
    int k_;
    vector<int>num;
    priority_queue<int,vector<int> ,greater<int>>pq;
    KthLargest(int k, vector<int>& nums) {
        k_=k;
        num = nums;
        for(int i:nums){
            pq.push(i);
            if(pq.size() > k) pq.pop();
        }
    }

    
    int add(int val) {
        num.push_back(val);
        pq.push(val);
        if(pq.size() > k_) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */