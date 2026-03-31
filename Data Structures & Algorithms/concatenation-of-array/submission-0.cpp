class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int N = nums.size();
        for(int i = 0; i < N; i++){
            nums.push_back(nums[i]);
        }
        return nums;
    }
};