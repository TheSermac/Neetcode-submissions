class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //Search the correct row to search:
        int a = 0; int b = matrix.size()-1;
        int row = (a+b)/2;
        while(a <= b){
            row = (a+b)/2;
            if(matrix[row][0] <= target && matrix[row][matrix[0].size()-1] >= target){
                if(matrix[row][0] == target || matrix[row][matrix[0].size()-1] == target) {
                    return true;
                }
                break;
            }
            else if(matrix[row][0] < target){
                a = row + 1;
            }
            else if(matrix[row][matrix[0].size()-1] > target){
                b = row - 1;
            }
        }

        //Search the row selected:
        a = 0; b = matrix[0].size()-1;
        while(a <= b){
            int m = (b + a)/2;
            if(matrix[row][m] == target){
                return true;
            }
            else if(matrix[row][m] < target){
                a = m + 1;
            }
            else{
                b = m - 1;
            }
        }

        return false;
    }
};
