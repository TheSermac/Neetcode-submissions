class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int result = 0; set<int> numbers;
        
        for(int num : nums){
            numbers.insert(num);
        }

        for(int num : nums){
            if(numbers.find(num-1) != numbers.end()){
                continue;
            }

            int aux = 1;
            while(numbers.find(num + aux) != numbers.end()){  aux++; }
            result = std::max(aux, result);
        }

        return result;
    }
};
