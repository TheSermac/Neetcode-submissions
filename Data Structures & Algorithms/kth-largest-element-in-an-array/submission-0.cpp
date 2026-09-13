class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,std::vector<int>,std::greater<int>> h_q;
        for(int num : nums){
            int elem = num;
            if(h_q.size() >= k){
                if(elem < h_q.top()){
                    elem = h_q.top();
                }
                h_q.pop();
            }
            h_q.push(elem);
        }
        return h_q.top();
    }
};
