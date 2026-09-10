class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int p1 = 0; int p2 = 0;
        while(true){
            int prev = p2;
            p1 = nums[p1];
            p2 = nums[nums[p2]];
            if(p1 == p2){
                break;
            }
        }

        int p3 = 0;
        while(true){
            p1 = nums[p1];
            p3 = nums[p3];
            if(p1 == p3){
                return p1;
            }
        }
    }
};
