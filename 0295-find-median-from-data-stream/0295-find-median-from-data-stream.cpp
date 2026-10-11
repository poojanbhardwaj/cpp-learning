
class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

    MedianFinder() {
    }

    void addNum(int num) {
        left.push(num);

        right.push(left.top());
        left.pop();

        if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian() {
        int n = left.size() + right.size();

        if (n & 1) {
            return left.top();
        }

        return ((double)left.top() + right.top()) / 2.0;
    }
};
