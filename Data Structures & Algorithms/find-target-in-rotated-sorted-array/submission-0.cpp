class Solution {
public:
    int search(vector<int>& nums, int target) {
        int a; int b;
        if(target > nums[nums.size()-1]){
            a = 0; 
            b = findMin(nums)-1;
        }
        else{
            a = findMin(nums);
            b = nums.size()-1;
        }

        if(a < 0 || a > nums.size()-1 || b < 0 || b > nums.size() - 1){
            return -1;
        }
        
        return search(nums, target, a, b);
    }

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

        return a;
    }

    int search(vector<int>& nums, int target, int l, int r) {
        int a = l; int b = r;
        while(a <= b){
            int m = (b + a)/2;
            if(nums[m] == target){
                return m;
            }
            else if(nums[m] < target){
                a = m + 1;
            }
            else{
                b = m - 1;
            }
        }

        return -1;
    }
};
