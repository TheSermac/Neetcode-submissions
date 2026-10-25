class Solution {
public:
    int rob(vector<int>& nums) {
        int houses = nums.size();
        // Handle edge cases to prevent out-of-bounds errors
        if (houses == 1) return nums[0];
        if (houses == 2) return std::max(nums[0], nums[1]);

        int prev1 = 0;
        int prev2 = 0;
        int curr = 0;

        for(int i = 0; i <= nums.size()-1; i++){
            curr = std::max(prev1, nums[i] + prev2);
            prev2 = prev1;
            prev1 = curr; 
        }

        return prev1;
    }
};
