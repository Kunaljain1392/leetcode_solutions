class Solution {
public:
    void dfs(int r, int c,vector<vector<char>>& board) {
        board[r][c] = '#';
        // top
        if(r-1 >= 0 && board[r-1][c] == 'O') {
            dfs(r-1,c,board);
        }
        // left
        if(c-1 >= 0 && board[r][c-1] == 'O') {
            dfs(r,c-1,board);
        }
        // down
        if(r+1 < board.size() && board[r+1][c]=='O' ) {
            dfs(r+1,c,board);
        }
        // right
        if(c+1 < board[0].size() && board[r][c+1] == 'O') {
            dfs(r,c+1,board);
        }


    }

    void solve(vector<vector<char>>& board) {
        int r = board.size();
        int c = board[0].size();
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                if(i == 0 || j == 0 || i == r-1 || j == c-1) {
                    if(board[i][j] == 'O') {
                        dfs(i,j,board);
                    }
                }
            }
        }

        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if(board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }

        return;
    }
};
