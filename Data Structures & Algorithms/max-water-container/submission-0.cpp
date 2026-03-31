class Solution {
public:
    int maxArea(vector<int>& heights) {
        int a = 0; int b = heights.size() - 1;
        int max = 0; int minSize = 0;

        while(b > a){
            //Check if new record
            minSize = std::min(heights[a], heights[b]);
            max = std::max(max, minSize * (b - a));

            //Who advances??
            if(heights[a] == minSize){
                a++;
            }
            else{
                b--;
            }
        }

        return max;
    }
};
