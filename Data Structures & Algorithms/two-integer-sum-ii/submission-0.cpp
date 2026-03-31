class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int a = 0; int b = numbers.size() - 1;
        vector<int> sol;

        while(numbers[a] + numbers[b] != target){
            if(numbers[a] + numbers[b] > target){
                b--;
            }
            else{
                a++;
            }
        }

        a++;b++;
        sol.push_back(a); sol.push_back(b);
        return sol;
    }
};
