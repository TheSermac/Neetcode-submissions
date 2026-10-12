class Solution {
private:
    vector<string> sol;
    string comb;

    std::vector<char> getLettersForDigit(char digit) {
    // Mapping based on the provided telephone keypad image.
    switch (digit) {
        case '2': return {'a', 'b', 'c'};
        case '3': return {'d', 'e', 'f'};
        case '4': return {'g', 'h', 'i'};
        case '5': return {'j', 'k', 'l'};
        case '6': return {'m', 'n', 'o'};
        case '7': return {'p', 'q', 'r', 's'};
        case '8': return {'t', 'u', 'v'};
        case '9': return {'w', 'x', 'y', 'z'};
        // Digits 0, 1, and symbols do not map to standard letters
        default: return {}; 
    }
}

    void createLetterCombinations(string digits){
        if(digits.empty()){
            sol.push_back(comb);
        }
        else{
            char digit = digits[0]; digits.erase(digits.begin());
            for(char phoneChar : getLettersForDigit(digit)){
                comb += phoneChar;
                createLetterCombinations(digits);
                comb.pop_back();
            }
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if(!digits.empty()){
            createLetterCombinations(digits);
        }
        return sol;
    }
};
