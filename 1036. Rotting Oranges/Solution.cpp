class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        // as they tell us to calculate time we will use BFS
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m));

        queue<pair<pair<int, int>, int>> q;
        //{{r,c},t} ->format for queue

        // finding the first rotten oranges & 
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2) 
                {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
                else
                {
                    vis[i][j]= 0; //marking rest of them 0. so it will help at end
                }
            }
        } 

        int time = 0;
        int delRow[4] = {-1, 0, 1, 0};
        int delCol[4] = {0, 1, 0, -1};
        // now use BFS
        while (!q.empty()) 
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            time = max(time,t); //each iteration e max time ta ber kre nicchi
            // traverse in the neighbour & mark if it's a land

            for (int i = 0; i < 4; i++) 
            {
                int nCol = c + delCol[i];
                int nRow = r + delRow[i];

                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && vis[nRow][nCol] != 2 && grid[nRow][nCol] ==1) // write condition for valid row & column, also see if it's neighbour & not visited [MOST IMPORTANT CONDITIONS]
                {
                    vis[nRow][nCol] = 2;
                    q.push({{nRow, nCol}, t + 1});
                }
            }
        }
            // for checking if there is any fresh orange
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1 && vis[i][j] != 2)
                return -1;
        }
    }
    return time;
    }

};