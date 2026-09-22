class MedianFinder {
private:
    priority_queue<int,std::vector<int>, std::less<int>> left;
    priority_queue<int,std::vector<int>, std::greater<int>> right;
    
public:
    MedianFinder() {}
    
    void addNum(int num) {
        //Add number in correct place
        if(!right.empty() && num < right.top()){
            left.push(num);
        }
        else{
            right.push(num);
        }
        
        //Resort the p_qs
        int diff = right.size() - left.size();
        while(diff > 1){
            left.push(right.top());
            right.pop();
            diff--; diff--;
        }

        diff = left.size() - right.size();
        while(diff > 1){
            right.push(left.top());
            left.pop();
            diff--; diff--;
        }
    }
    
    double findMedian() {
        double median = 0;
        if(right.size() == left.size()){
            median = (right.top() + left.top()) / 2.0;
        }
        else if(left.size() > right.size()){
            median = (double) left.top();
        }
        else{
            median = (double) right.top();
        }
        return median;
    }
};