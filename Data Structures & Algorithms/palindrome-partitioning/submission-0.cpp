class Solution {
private:
    vector<string> curr;
    vector<vector<string>> sol;

    bool isPalindrome(const string& s, int i, int j){
        while(i < j){
            if(s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }

    void findPartitions(string s, int i){
        if(i == s.length()){
            sol.push_back(curr);
        }
        else{
            for(int j = i; j < s.length(); j++) {
                if(isPalindrome(s, i, j)) {
                    curr.push_back(s.substr(i, j-i+1));
                    findPartitions(s,j+1);
                    curr.pop_back();
                }
            }
        }
    }

public:
    vector<vector<string>> partition(string s, int i = 0) {
        findPartitions(s,i);
        return sol;
    }
};
