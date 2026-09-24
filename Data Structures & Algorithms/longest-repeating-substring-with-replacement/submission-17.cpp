class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0; int right = 0;
        int maxFreq = 0; int answer = 0;

        map<char, int> freq;

        while (right < s.length()) {
            // Add current character to the window
            freq[s[right]]++;

            // Keep track of the highest frequency
            maxFreq = max(maxFreq, freq[s[right]]);

            // If we need more than k replacements,
            // shrink the window from the left
            while ((right - left + 1) - maxFreq > k) {
                freq[s[left]]--;
                left++;
            }

            // Current window is valid
            answer = max(answer, right - left + 1);

            right++;
        }

        return answer;
    }
};
