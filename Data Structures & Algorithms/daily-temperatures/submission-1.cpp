class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> maxTemp;
        vector<int> sol;

        for(int i = temperatures.size() - 1; i >= 0; i--){
            while(!maxTemp.empty() && maxTemp.top().second <= temperatures[i]){
                maxTemp.pop();
            }
            if(maxTemp.empty()){
                sol.insert(sol.begin(), 0);
            }
            else{
                sol.insert(sol.begin(),maxTemp.top().first - i);
            }
            maxTemp.push({i, temperatures[i]});
        }

        return sol;
    }
};
