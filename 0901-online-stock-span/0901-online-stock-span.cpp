class StockSpanner {
public:
    StockSpanner() {
        
    }
   
    
    int ind = 0;stack<pair<int,int>> st;
    int next(int price) {
        ind++;
       
       while(!st.empty() && st.top().second<= price){
        st.pop();
       }
       int ans;
        if(st.empty())ans =  ind;
        else{
            ans=  ind-st.top().first;
        }
        st.push({ind,price});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */