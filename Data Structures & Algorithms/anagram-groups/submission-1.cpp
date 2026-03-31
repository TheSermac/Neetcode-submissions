class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<int, vector<string>> allocate; int val = 0;
        vector<vector<string>> sol;

        for(string s : strs){
            for(char c : s){
                val += c * c;
            }
            allocate[val].push_back(s);
            val = 0;
        }

        for(auto it = allocate.begin(); it != allocate.end(); ++it){
            sol.push_back(it->second);
        }

        return sol;
    }
};
