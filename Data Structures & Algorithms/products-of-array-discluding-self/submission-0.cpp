class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       int other_result = 0; int result = 1; int zero_count = 0; vector<int> sol (nums.size(), 0);

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                result *= nums[i];
            }
            else{
                zero_count++;
            }
        }

        if(zero_count >= 2){
            return sol;
        }

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                sol[i] = result;
                continue;
            }
            else if(zero_count == 1){
                sol[i] = 0;
                continue;
            }
            sol[i] = result / nums[i];
        }

        return sol;
    }
};
