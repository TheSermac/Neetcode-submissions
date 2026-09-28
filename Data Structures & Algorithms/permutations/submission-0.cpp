class Solution {
private:
    vector<vector<int>> sol;
    vector<int> currPer;

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> idxToChoose(nums.size(), true);
        createPermutations(nums, idxToChoose);
        return sol;
    }

    void createPermutations(vector<int>& nums, vector<bool>& idxToChoose){
        if(!currPer.empty() && nums.size() == currPer.size()){
            sol.push_back(currPer);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(idxToChoose[i]){
                idxToChoose[i] = false;
                currPer.push_back(nums[i]);
                createPermutations(nums, idxToChoose);
                idxToChoose[i] = true;
                currPer.pop_back();
            }
        }
    }
};
