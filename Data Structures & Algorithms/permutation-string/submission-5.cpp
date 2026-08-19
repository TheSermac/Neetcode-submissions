class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.length() < s1.length()){
            return false;
        }
        else if(s2.length() == s1.length()){
            sort(s1.begin(), s1.end());
            sort(s2.begin(), s2.end());
            return s2 == s1;
        }
        else{
            sort(s1.begin(), s1.end());
            for(int i = 0; i < s2.length(); i++){
                if(s1.find(s2[i]) != std::string::npos && i + s1.length() - 1 < s2.length()){
                    string perm = s2.substr(i, s1.length());
                    sort(perm.begin(), perm.end());
                    if(perm == s1){
                        return true;
                    }
                }
            }
            return false;
        }
    }
};
