class Solution {
private:
    vector<int> stairs;
public:
    int climbStairs(int n) {
        int first = 2;
        int second = 1;

        if(n == 1){
            return 1;
        }
        if(n == 2){
            return 2;
        }
        for(int i = 3; i <= n; i++){
            stairs.push_back(first + second);
            second = first;
            first = stairs[stairs.size()-1];
        }

        return first;
    }
};
