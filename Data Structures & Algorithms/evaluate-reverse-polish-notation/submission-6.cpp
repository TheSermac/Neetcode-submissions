class Solution {

private:
    const int ZERO = '0';
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> operands;

        for(int i = 0; i < tokens.size(); i++){
            if(convertible(tokens[i])){
                operands.push(convert(tokens[i]));
            }
            else {
                int operand2 = operands.top(); operands.pop();
                int operand1 = operands.top(); operands.pop();
                operands.push(operate(operand1, operand2, tokens[i]));
            }
        }

        return operands.top();
    }

    int operate(int a, int b, string sign){
        switch(sign[0]){
            case '+':
                return a+b;
            case '-':
                return a-b;
            case '*':
                return a*b;
            case '/':
                return a/b;
            default:
                return -1;
        }
    }

    int convert(string c){
        int r = 0;
        for(int i = c[0] == '-' ? 1 : 0; i < c.length(); i++){
            r += c[i] - ZERO;
            r *= 10;
        }
        return c[0] == '-' ? -r/10 : r/10;
    }

    bool convertible(string c){
        switch(c[0]){
            case '+':
            case '-':
            case '*':
            case '/':
                return c.length() != 1;
            default:
                return true;
        }
    }
};
