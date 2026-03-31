class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string sol = strs[0]; string aux = "";

        for(int i = 1; i < strs.size(); i++){
            aux = "";
            for(int j = 0; j < std::min(sol.length(), strs[i].length()); j++){
                if(sol[j] == strs[i][j]){
                    aux += sol[j];
                }
                else{
                    break;
                }
            }
            sol = aux;
        }

        return sol;
    }
};