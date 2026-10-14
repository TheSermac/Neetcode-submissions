class Solution {
private:
    vector<bool> column;
    vector<bool> left_diagonal;
    vector<bool> right_diagonal;
    vector<vector<string>> sol;
    vector<string> curr;
    int chessboard;

    string convertToString(int i){
        string ret;
        for(int points = 0; points < i; points++){
            ret += '.';
        }
        ret += 'Q';
        for(int points = i+1; points < chessboard; points++){
            ret += '.';
        }
        return ret;
    }

    bool valid(int r, int c){
        return column[c] && left_diagonal[r - c + chessboard - 1] && right_diagonal[r + c];
    }

    void placeNQueens(int row){
        if(row == chessboard){
            sol.push_back(curr);
        }
        else{
            for(int col = 0; col < chessboard; col++){
                if(valid(row, col)){
                    column[col] = false;
                    left_diagonal[row - col + chessboard - 1] = false;
                    right_diagonal[row + col] = false;
                    curr.push_back(convertToString(col));
                    placeNQueens(row+1);
                    column[col] = true;
                    left_diagonal[row - col + chessboard - 1] = true;
                    right_diagonal[row + col] = true;
                    curr.pop_back();
                }
            }
        }
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        column = vector<bool> (n, true);
        left_diagonal = vector<bool> (2*n - 1, true);
        right_diagonal = vector<bool> (2*n - 1, true);
        chessboard = n;
        placeNQueens(0);
        return sol;
    }
};
