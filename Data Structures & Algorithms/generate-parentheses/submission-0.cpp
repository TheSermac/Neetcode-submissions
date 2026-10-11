class Solution {
private:
    vector<string> sol;
    string curr;
    int total;

    void createParenthesis(int iteration, int no_paired){
        if(iteration == total){
            if(no_paired == 0){
                sol.push_back(curr);
            }
        }
        else{
            curr += "(";
            createParenthesis(iteration+1, no_paired+1);
            curr.pop_back();

            if(no_paired > 0){
                curr += ")";
                createParenthesis(iteration+1, no_paired-1);
                curr.pop_back();
            }
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        total = 2 * n;
        createParenthesis(0,0);
        return sol;
    }
};
