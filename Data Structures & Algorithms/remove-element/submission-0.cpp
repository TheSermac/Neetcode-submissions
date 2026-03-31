class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0; vector<int> sol;
        for(int num : nums){
            if(num != val){
                sol.push_back(num);
                k++;
            }
        }

        nums = sol;
        
        return k;
    }
};