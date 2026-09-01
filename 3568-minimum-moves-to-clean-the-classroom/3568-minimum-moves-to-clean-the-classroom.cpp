class Solution {
public:
    struct State {
        int r, c;
        int energy;
        int mask;
    };

    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int mxe = energy;

        int litterBit[20][20];
        int litterCnt = 0;

        int sr = 0, sc = 0;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                litterBit[r][c] = -1;

                if (classroom[r][c] == 'S') {
                    sr = r;
                    sc = c;
                }
                else if (classroom[r][c] == 'L') {
                    litterBit[r][c] = litterCnt++;
                }
            }
        }

        int allCollected = (1 << litterCnt) - 1;

        if (litterCnt == 0) {
            return 0;
        }

        queue<State> que;

        // {row, col, current energy, collected litter mask}
        que.push({sr, sc, mxe, 0});

        // visited[r][c][energy][mask]
        vector<vector<vector<vector<bool>>>> visited(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    mxe + 1,
                    vector<bool>(1 << litterCnt, false)
                )
            )
        );

        visited[sr][sc][mxe][0] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        int moves = 0;

        while (!que.empty()) {
            int sz = que.size();

            while (sz--) {
                State cur = que.front();
                que.pop();

                int r = cur.r;
                int c = cur.c;
                int e = cur.energy;
                int mask = cur.mask;

                if (mask == allCollected) {
                    return moves;
                }

                // Cannot move without energy.
                if (e == 0) {
                    continue;
                }

                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    // Outside classroom
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                        continue;
                    }

                    // Wall
                    if (classroom[nr][nc] == 'X') {
                        continue;
                    }

                    int ne = e - 1;
                    int nmask = mask;

                    // Collect litter
                    if (classroom[nr][nc] == 'L') {
                        int bit = litterBit[nr][nc];
                        nmask |= (1 << bit);
                    }

                    // Recharge cell
                    if (classroom[nr][nc] == 'R') {
                        ne = mxe;
                    }

                    if (!visited[nr][nc][ne][nmask]) {
                        visited[nr][nc][ne][nmask] = true;
                        que.push({nr, nc, ne, nmask});
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};