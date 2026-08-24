class Solution {
public:
    void dfs(int i, int j, vector<vector<bool>> &visited,
    vector<vector<int>>& grid, int& area) {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || visited[i][j] ||
         grid[i][j] != 1) {
            return;
        }
        visited[i][j] = true;
        area++;
        dfs(i-1,j,visited,grid,area); //top;
        dfs(i,j-1,visited,grid,area); //left;
        dfs(i+1,j,visited,grid,area); //bottom;
        dfs(i,j+1,visited,grid,area); //right;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n,vector<bool> (m,false));
        int ans = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                int area=0;
                if(!visited[i][j] && grid[i][j] == 1) {
                    dfs(i,j,visited,grid,area);
                }
                ans = max(ans,area);
            }
        }

        return ans;

    }
};
