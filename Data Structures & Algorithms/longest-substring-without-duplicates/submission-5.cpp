class Solution {
public:
        int lengthOfLongestSubstring(string s) {
        int result = !s.empty() ? 1 : 0; 
        int a = 0; int b = 0;
        set<char> done;

        while(b < s.length()){
            if(done.find(s[b]) != done.end()){
                result = std::max(result, b - a);
                while(s[a] != s[b]){done.erase(s[a]); a++;} a++;
                done.erase(s[b]);
            }
            
            done.insert(s[b]);
            b++;
        }

        return std::max(result, b - a);
    }
};
