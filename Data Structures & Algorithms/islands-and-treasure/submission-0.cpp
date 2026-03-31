class Solution {
public:
    const vector<pair<int, int>> moves = {
        {0,1}, {0,-1}, {1,0}, {-1,0}
    };

    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        //Search for treasures
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    q.push({ i,j });
                    visited[i][j] = true;
                }
            }
        }

        //Use BFS 
        while (!q.empty()) {
            pair<int, int> aux = q.front(); q.pop();
            for (pair<int, int> mo : moves) {
                if (isValid({ aux.first + mo.first, aux.second + mo.second }, n, m) 
                    && grid[aux.first + mo.first][aux.second + mo.second] != -1
                    && !visited[aux.first + mo.first][aux.second + mo.second]) {
                    grid[aux.first + mo.first][aux.second + mo.second] = grid[aux.first][aux.second] + 1;
                    visited[aux.first + mo.first][aux.second + mo.second] = true;
                    q.push({ aux.first + mo.first, aux.second + mo.second });
                }
            }
        }
    }

    // Check if a position is valid inside an m×n board
    bool isValid(pair<int, int> pos, int m, int n) {
        int x = pos.first;
        int y = pos.second;
        return (x >= 0 && x < m && y >= 0 && y < n);
    }
};