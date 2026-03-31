class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> diff; int val = 0;
        vector<int> sol;

        for(int i = 0; i < nums.size(); i++){
            val = target - nums[i];
            if(diff.count(nums[i])){
                sol.push_back(diff[nums[i]]); sol.push_back(i);
                return sol;
            }
            else{
                diff[val] = i;
            }
        }

        return sol;
    }
};
