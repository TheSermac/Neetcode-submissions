class Solution {
public:
    bool isPalindrome(string s) {
        string corrected;

        for(char c : s){
            if(c >= 'A' && c <= 'Z'){
                corrected += (c + 32);
            }
            else if((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')){
                corrected += c;
            }
        }

        int a = corrected.length() % 2 == 0 ? (corrected.length() / 2) - 1: corrected.length() / 2; 
        int b = corrected.length() / 2;

        while(a >= 0){
            if(corrected[a] != corrected[b]){
                return false;
            }
            else{
                a--;b++;
            }
        }

        return true;
    }
};
