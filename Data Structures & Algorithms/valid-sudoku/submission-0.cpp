class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<int>> rows(9); 
        vector<set<int>> cols(9);
        vector<set<int>> box(9);

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == '.'){
                    continue;
                }

                int val = board[i][j] - '0';
                
                //Rows
                if(rows[i].find(val) != rows[i].end()){
                    return false;
                }
                else {
                    rows[i].insert(val);
                }

                //Columns
                if(cols[j].find(val) != cols[j].end()){
                    return false;
                }
                else {
                    cols[j].insert(val);
                }

                //Blocks
                int block = 3*(i/3) + j/3 ;
                if(box[block].find(val) != box[block].end()){
                    return false;
                }
                else {
                    box[block].insert(val);
                }
            }
        }

        return true;
    }

    
};
