class Solution {
public:
    void dfs(int i, int j,vector<vector<bool>>& visited,
    vector<vector<char>>& grid  ) {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] != '1' || visited[i][j] ) {
            return;
        }

        visited[i][j] = true;

        
        dfs(i-1,j,visited,grid);    //top
        dfs(i,j-1,visited,grid);    //left
        dfs(i+1,j,visited,grid);    //bottom
        dfs(i,j+1,visited,grid);    //right
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n,vector<bool> (m,false));
        int cnt = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == '1' && !visited[i][j]) {
                    dfs(i,j,visited,grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};