class Solution {
public:
    int findMin(vector<int> &nums) {
        int a = 0; int b = nums.size()-1;
        while(nums[a] > nums[b]){
            int m = (b+a)/2;

            if(nums[m] > nums[b]){
                a = m + 1;
            }
            else {
                b = m;
            }
        }

        return nums[a];
    }
};
