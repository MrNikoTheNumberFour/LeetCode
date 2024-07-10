class Solution {
    private:
    void dfs(int sr, int sc, vector<vector<int>>& visited, vector<vector<int>>& image, int newColor, int initialColor)
    {
        visited[sr][sc]= newColor;

        int n = image.size();
        int m = image[0].size();

        int delRow[4] = {-1, 0, 1, 0};
        int delCol[4] = {0, 1, 0, -1};
            // traverse in the neighbour & mark if it's a land

            for (int i = 0; i < 4; i++)
            {
                int nCol = sc + delCol[i];
                int nRow = sr + delRow[i];

                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && image[nRow][nCol]==initialColor && visited[nRow][nCol]!= newColor)       // write condition for valid row & column, also see if it's land & not visited [MOST IMPORTANT CONDITIONS]
                {
                    dfs(nRow,nCol,visited,image,newColor,initialColor);
                }
            }
        
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        //easiest problem to solve
        int initialColor = image[sr][sc];
        vector<vector<int>>cpyImage = image;

        dfs(sr,sc,cpyImage,image,color,initialColor);
        return cpyImage;
    }
};