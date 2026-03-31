class Solution {
public:
    bool isValid(string s) {
        stack<char> count;
        map<char,char> relate = {
            {'(', ')'},
            {'[', ']'},
            {'{', '}'},
        };


        for(char c : s){
            if(c == '(' || c == '{' || c == '['){
                count.push(c);
            }
            else if(c == ')' || c == '}' || c == ']'){
                if(count.empty() || c != relate[count.top()]){
                    return false;
                }
                count.pop();
            }
            else{
                return false;
            }
        }

        return count.empty();
    }
};
