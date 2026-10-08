class Solution {
private:
const vector<pair<int,int>> dir = {{1,0}, {0,1}, {-1,0}, {0, -1}};

    bool searchWord(vector<vector<char>>& board, string& word, vector<vector<bool>>& visited, int i, int j, int index){
        //If we already found the entire word we finish
        if(index >= word.length()){
            return true;
        }

        for(pair<int,int> direction : dir){
            int newI = i + direction.first;
            int newJ = j + direction.second;
            //Check:
            // that newI, newJ is in a valid position
            // that the position has not been visited already
            // that the element in that position is equal to word[index]
            if(newI < board.size() && newJ < board[0].size() &&
            newI >= 0 && newJ >= 0 && !visited[newI][newJ] && 
            board[newI][newJ] == word[index]){
                visited[newI][newJ] = true;
                if(searchWord(board, word, visited, i+direction.first, j+direction.second, index+1)){
                    return true;
                }
                visited[newI][newJ] = false;
            }
        }

        //If no letter coincides with word[index], we failed in this path
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        //Initialize the visited array
        vector<vector<bool>> visited(board.size(), vector<bool> (board[0].size(), false));

        //Visit each element in the board until 
        // we find a letter that coincides with the initial letter of word
        for(int i = 0;  i <  board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                visited[i][j] = true;
                //We check the letter and use backtracking in case it coincides
                if(board[i][j] == word[0] && searchWord(board, word, visited, i, j, 1)){
                    return true;
                }
                visited[i][j] = false;
            }
        }

        return false;
    }
};
