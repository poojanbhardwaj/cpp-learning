

class Solution {
public:
     vector<int> sequentialDigits(int low, int high){
        vector<int> result;

        for (int length = 2; length <= 9; ++length) {
            for (int first = 1; first + length <= 10; ++first) {
                int value = 0;

                for (int digit = first; digit < first + length; ++digit) {
                    value = value * 10 + digit;
                }

                if (value >= low && value <= high) {
                    result.push_back(value);
                }
            }




            
        }

        return result;
    }
};