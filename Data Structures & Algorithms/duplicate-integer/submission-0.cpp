class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int,bool> alreadyAppeared;

        for(int num : nums){
            if(alreadyAppeared[num]){
                return true;
            }
            else{
                alreadyAppeared[num] = true;
            }
        }

        return false;
    }
};