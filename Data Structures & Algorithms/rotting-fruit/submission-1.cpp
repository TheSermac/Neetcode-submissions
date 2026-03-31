class Solution {
private:
    const vector<pair<int,int>> MOVES = {{1,0},{0,1},{-1,0},{0,-1}};
    const int INF = 1e9;
public:

    bool valid(pair<int,int> coord, int i, int j) {
        return coord.first >= 0 && coord.first < i && coord.second >= 0 && coord.second < j;
    }

    int bfs(const vector<vector<int>>& grid, vector<vector<int>>& count, queue<pair<int,int>>& q, int& totalOranges){
        vector<vector<bool>> visited(grid.size(), vector<bool> (grid[0].size(), false)); 
        int maxOrangeRot = 0;
        while(!q.empty()){
            pair<int,int> coord = q.front(); q.pop();
            
            for(pair<int,int> dir : MOVES){
                if(valid({coord.first+ dir.first, coord.second + dir.second}, grid.size(), grid[0].size()) 
                && grid[coord.first + dir.first][coord.second + dir.second] == 1 
                && count[coord.first][coord.second] + 1 > count[coord.first+ dir.first][coord.second + dir.second]
                && !visited[coord.first+ dir.first][coord.second + dir.second]){
                    if(count[coord.first+ dir.first][coord.second + dir.second] == 0){
                        totalOranges = totalOranges + 1;
                    }
                    
                    q.push({coord.first+ dir.first, coord.second + dir.second});
                    visited[coord.first+ dir.first][coord.second + dir.second] = true;
                    count[coord.first+ dir.first][coord.second + dir.second] = count[coord.first][coord.second] + 1;
                    maxOrangeRot = max(count[coord.first][coord.second] + 1, maxOrangeRot);
                }
            }
        }

        return maxOrangeRot;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> visited(grid.size(), vector<int> (grid[0].size(), 0));
        int safeOranges = 0; int totalOranges = 0; int sol = 0; queue<pair<int,int>> q; 

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1) {
                    safeOranges++;
                }
                
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }

        sol = bfs(grid, visited, q, totalOranges);

        return safeOranges == totalOranges ? sol : -1;
    }
};