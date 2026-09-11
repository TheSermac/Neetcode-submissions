class KthLargest {
private:
    priority_queue<int,std::vector<int>,std::less<int>> k_queue;
    int k;
public:
    KthLargest(int k, vector<int>& nums) : k(k){
        for(int i = 0; i < nums.size(); i++){
            k_queue.push(nums[i]);
        }
    }
    
    int add(int val) {
        k_queue.push(val);

        vector<int> temp;
        for(int i = 0; i < k; i++){
            temp.push_back(k_queue.top());
            k_queue.pop();
        }
        
        for(int i = 0; i < temp.size(); i++){
            k_queue.push(temp[i]);
        }

        return temp[temp.size()-1];
    }
};
