class Solution {
private:
    vector<vector<int>> total_subsets;

    void createSubsets(vector<int>& nums, vector<int>& curr_subset, int index){
        total_subsets.push_back(curr_subset);
        for(int i = index; i < nums.size(); i++){
            if (i > index && nums[i] == nums[i - 1]) {
                continue;
            }

            curr_subset.push_back(nums[i]);
            createSubsets(nums, curr_subset,i+1);
            curr_subset.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> subset;
        sort(nums.begin(), nums.end());
        createSubsets(nums, subset, 0);
        return total_subsets;
    }
};
