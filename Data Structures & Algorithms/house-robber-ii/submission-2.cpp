class Solution {
private: 
    int robRange(vector<int>& nums, int start, int finish){
        int prev1 = 0;
        int prev2 = 0;
        int curr = 0;

        for(int i = start; i <= finish; i++){
            curr = std::max(prev1, nums[i] + prev2);
            prev2 = prev1;
            prev1 = curr; 
        }

        return prev1;
    }
public:
    int rob(vector<int>& nums) {
        int houses = nums.size();
        // Handle edge cases to prevent out-of-bounds errors
        if (houses == 1) return nums[0];
        if (houses == 2) return std::max(nums[0], nums[1]);

        return std::max(robRange(nums, 0, houses-2), robRange(nums, 1, houses-1));
    }
};
