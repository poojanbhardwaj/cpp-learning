class Solution {
public:
    bool sumGame(string num) {
       
        int sumr = 0,suml =0 ,n = num.size(),ql = 0,qr= 0;
        int mid = n/2;
        for(int i = 0;i<mid;i++){
            if(num[i] == '?'){
                ql++;
               
                continue;
                
            }
            else
            suml+=num[i]-'0';

            
        }
         for(int i = mid;i<n;i++){
            if(num[i] == '?'){
                qr++;
               
                continue;
                
            }
            else
            sumr+=num[i]-'0';

            
        }
        return ((qr+ql)%2 == 1)|| (suml-sumr != (qr-ql)*9/2);
    }
};