#include<iostream> 
#include<queue>
using namespace std;

class Solution {
private:
    const vector<pair<int,int>> MOVES = {{1,0},{0,1},{-1,0},{0,-1}};

public:
    bool valid(pair<int,int> coord, int i, int j) {
        return coord.first >= 0 && coord.first < i && coord.second >= 0 && coord.second < j;
    }

    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));
        int sol = 0;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    bfs(grid, visited, i, j);
                    sol++;
                }
            }
        }

        return sol;
    }

    void bfs(const vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j){
        queue<pair<int,int>> q; q.push({i, j}); visited[i][j] = true;
        while(!q.empty()){
            pair<int,int> coord = q.front(); q.pop();
            
            for(pair<int,int> dir : MOVES){
                if(valid({coord.first+ dir.first, coord.second + dir.second}, grid.size(), grid[0].size()) 
                && grid[coord.first + dir.first][coord.second + dir.second] == '1' 
                && !visited[coord.first+ dir.first][coord.second + dir.second]){
                    q.push({coord.first+ dir.first, coord.second + dir.second});
                    visited[coord.first+ dir.first][coord.second + dir.second] = true;
                }
            }
        }
    }
};

