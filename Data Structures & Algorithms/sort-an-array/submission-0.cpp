class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>, std::greater<int>> aux;

        for(int num : nums){
            aux.push(num);
        }

        for(int i = 0; i < nums.size(); i++){
            nums[i] = aux.top(); aux.pop();
        }

        return nums;
    }
};