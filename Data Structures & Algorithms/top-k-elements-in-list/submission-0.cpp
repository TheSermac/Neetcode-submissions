class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> numToFreq; vector<int> sol; 

        for(int num : nums){
            numToFreq[num]++;
        }

        vector<pair<int,int>> orderedByK;
        for(auto num : numToFreq){
            orderedByK.push_back({num.second, num.first});
        }

        sort(orderedByK.begin(), orderedByK.end(), std::greater<>());

        for(int i = 0; i < k; i++){
            sol.push_back(orderedByK[i].second);
        }

        return sol;
    }
};
