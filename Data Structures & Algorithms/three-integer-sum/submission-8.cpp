class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> sol; int a; int b;
        set<pair<int,pair<int,int>>> visited;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size() && nums[i] <= 0; i++){
            a = i + 1; b = nums.size() - 1;
            while(b > a){
                if(nums[i] + nums[a] + nums[b] == 0){
                    if(visited.find({nums[i], {nums[a], nums[b]}}) == visited.end()){
                        sol.push_back({nums[i], nums[a], nums[b]});
                        visited.insert({nums[i], {nums[a], nums[b]}});
                    }
                    a++; b--;
                }
                else if(nums[i] + nums[a] + nums[b] < 0){
                    a++;
                }
                else{
                    b--;
                }
            }
        }

        return sol;
    }
};
