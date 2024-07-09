class Solution
{

public:
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid)
    {
        vis[row][col] = 1; // marked starting node = 1
        queue<pair<int, int>> q;
        q.push({row, col});

        int n = grid.size();
        int m = grid[0].size();

        int delRow[4] = {-1, 0, 1, 0};
        int delCol[4] = {0, 1, 0, -1};

        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second; // storing node
            q.pop();

            // traverse in the neighbour & mark if it's a land

            for (int i = 0; i < 4; i++)
            {
                int nCol = col + delCol[i];
                int nRow = row + delRow[i];

                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && vis[nRow][nCol] == 0 && grid[nRow][nCol] == '1') // write condition for valid row & column, also see if it's land & not visited
                {
                    vis[nRow][nCol] = 1;
                    q.push({nRow, nCol});
                }
            }
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size(); // finding  the row & columns of grid

        int cnt = 0;

        vector<vector<int>> vis(n, vector<int>(m, 0)); // creating a 2D visited array to mark visited nodes

        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                if (!vis[row][col] && grid[row][col] == '1')
                {
                    cnt++;
                    bfs(row, col, vis, grid);
                }
            }
        }
        return cnt;
    }
};