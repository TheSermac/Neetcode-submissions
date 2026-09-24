class Solution {
private:
    vector<vector<int>> subparts;
    vector<int> tmp;

    void createSubsets(vector<int>& nums, vector<int>& newSet, int prev){
        for(int i = 0; i <= nums.size(); i++){
            if(i == 0){
                subparts.push_back(newSet);
            }
            else if(i > prev){
                newSet.push_back(nums[i-1]);
                createSubsets(nums,newSet, i);
                newSet.pop_back();
            }
        }
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        createSubsets(nums, tmp, -1);
        return subparts;
    }
};
