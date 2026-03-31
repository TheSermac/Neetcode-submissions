class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string;

        for(string str : strs){
            encoded_string += str;
            encoded_string += "W1W";
        }

        for(int i = 0; i < encoded_string.length(); i++){
            encoded_string[i] += 32;
        }

        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> decode_string;
        string translate = s;

        for(int i = 0; i < s.length(); i++){
            translate[i] -= 32;
        }

        string auxStr;
        for(int i = 0; i < translate.length(); i++){
            if(translate[i] == 'W' && translate[i+1] == '1' && translate[i+2] == 'W'){
                decode_string.push_back(auxStr);
                auxStr = "";
                i++; i++;
            }
            else{
                auxStr += translate[i];
            }
        }

        return decode_string;
    }
};
