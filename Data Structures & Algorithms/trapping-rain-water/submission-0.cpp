class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>maxLeft(height.size()); vector<int>maxRight(height.size());
        int min = 0; int sol = 0;

        for(int i = 0; i < height.size(); i++){
            if(i == 0 || maxLeft[i - 1] < height[i]){
                maxLeft[i] = height[i];
            }
            else{
                maxLeft[i] = maxLeft[i - 1];
            }
        }

        for(int i = height.size() - 1; i >= 0; i--){
            if(i == height.size() - 1 || maxRight[i + 1] < height[i]){
                maxRight[i] = height[i];
            }
            else{
                maxRight[i] = maxRight[i + 1];
            }
        }

        for(int i = 0; i < height.size(); i++){
            sol += std::min(maxLeft[i], maxRight[i]) - height[i]; 
        }

        return sol;
    }
};
