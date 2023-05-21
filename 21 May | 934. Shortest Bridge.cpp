class Solution {
public:

    vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1, 0}};

    void dfs(vector<vector<int>>& grid, int x, int y, queue<pair<int, int>>& q){
        int n = grid.size();
        grid[x][y] = 2;
        q.push({x,y});

        for(auto d : dir){
            int newX = x + d[0];
            int newY = y + d[1];

            if(newX >= 0 && newX < n && newY >= 0 && newY < n && grid[newX][newY] == 1){
                dfs(grid, newX, newY, q);
            }
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int firstX = -1, firstY = -1;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    firstX = i;
                    firstY = j;
                    break;
                }
            }
        }
        queue<pair<int, int>>q;
        dfs(grid, firstX, firstY, q);
        int dist = 0;

        while(!q.empty()){
            int sz = q.size();

            while(sz--){
                int currX = q.front().first, currY = q.front().second;
                q.pop();

                for(auto d: dir){
                    int newX = currX + d[0];
                    int newY = currY + d[1];
                    if(newX >= 0 && newX < n && newY >= 0 && newY < n && grid[newX][newY] == 1){
                        return dist;
                    }
                    else if(newX >= 0 && newX < n && newY >= 0 && newY < n && grid[newX][newY] == 0){
                        grid[newX][newY] = -1;
                        q.push({newX, newY});
                    }
                }
            }
            dist++;
        }
        return dist;
    }
};
