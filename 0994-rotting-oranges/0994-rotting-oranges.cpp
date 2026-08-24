class Solution {
public:
    void bfs(vector<vector<bool>>& visited,
    vector<vector<int>>& grid, int& time, int& fresh) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == 2) {
                    q.push({i,j});
                    visited[i][j] = true;
                } else if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        while(!q.empty() && fresh > 0) {
            int size = q.size();
            

            for(int k=0;k<size;k++) {
                pair<int,int> front = q.front();
                q.pop();
                int r = front.first, c = front.second;
                // top
                if(r-1 >= 0 && grid[r-1][c] == 1 
                && !visited[r-1][c]) {
                    grid[r-1][c] = 2;
                    q.push({r-1,c});
                    visited[r-1][c] = true;
                    fresh--;
                }
                // left
                if(c-1 >= 0 && grid[r][c-1] == 1
                 && !visited[r][c-1]) {
                    grid[r][c-1] = 2;
                    q.push({r,c-1});
                    visited[r][c-1] = true;
                    fresh--;
                }
                // bottom
                if(r+1<grid.size() && grid[r+1][c] == 1 
                && !visited[r+1][c]) {
                    grid[r+1][c] = 2;
                    q.push({r+1,c});
                    visited[r+1][c] = true;
                    fresh--;
                }
                // right
                if(c+1<grid[r].size() && grid[r][c+1] == 1 && !visited[r][c+1]) {
                    grid[r][c+1] = 2;
                    q.push({r,c+1});
                    visited[r][c+1] = true;
                    fresh--;
                }
            }

            time++;
            
        }


    }

    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0;
        int fresh = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n,vector<bool> (m,false));

        bfs(visited,grid,time,fresh);

        if(fresh>0) {
            return -1;
        }

        return time;


        



    }
};
