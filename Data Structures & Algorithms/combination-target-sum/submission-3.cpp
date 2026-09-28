class Solution {
private:
    vector<vector<int>> sol;
    vector<int> currComb;

public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        createCombination(nums, target, 0);
        return sol;
    }

    void createCombination(vector<int>& nums, int leftToTarget, int index){
        if(leftToTarget == 0){
            sol.push_back(currComb);
            return;
        }
        else if(leftToTarget < 0){
            return;
        }

        for(int i = index; i < nums.size(); i++){
            currComb.push_back(nums[i]);
            createCombination(nums, leftToTarget - nums[i], i);
            currComb.pop_back();
        }
    }

};
