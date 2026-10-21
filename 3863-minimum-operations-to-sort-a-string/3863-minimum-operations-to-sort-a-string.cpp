class Solution {
public:
    int minOperations(string s) {
        if (is_sorted(s.begin(), s.end())) return 0;
        int n = s.size();
        if (n < 3) return -1;

        auto [mi, ma] = minmax_element(s.begin(), s.end());

        if (s.front() == *mi || s.back() == *ma) return 1;

        int c1 = 0, c2 = 0;
        for (char c : s) {
            if (c == *ma) c1++;
            if (c == *mi) c2++;
        }

        if (s.front() == *ma && s.back() == *mi && c1 == 1 && c2 == 1) return 3;

        return 2;
    }
};