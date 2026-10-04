class Solution {
private:
    vector<vector<int>> sol;
    vector<int> currComb;
    
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
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

        int lastNum = 0;
        for(int i = index; i < nums.size(); i++){
            if(nums[i] != lastNum){
                currComb.push_back(nums[i]);
                createCombination(nums, leftToTarget - nums[i], i + 1);
                currComb.pop_back();
            }
            lastNum = nums[i];
        }
    }

};