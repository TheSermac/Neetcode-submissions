class Solution {
private:
    vector<vector<int>> sol;
    vector<int> currComb;

public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        createCombination(nums, target, 0);

        return sol;
    }

    void createCombination(vector<int>& nums, int target, int idx) {
        if (target == 0) {
            sol.push_back(currComb);
            return;
        }

        for (int i = idx; i < nums.size(); i++) {
            if (nums[i] > target)
                break;

            currComb.push_back(nums[i]);

            createCombination(nums, target - nums[i], i);

            currComb.pop_back();
        }
    }
};