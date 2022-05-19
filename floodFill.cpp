#include <vector>

std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, 
                                        int sr, int sc, int newColor) 
{
    if (image[sr][sc] == newColor) { return image; }
    std::vector<std::pair<int, int>> pixels;
    int direction[4][2] = {{1,0},{-1, 0},{0,1},{0,-1}};
    int oldColor = image[sr][sc], m = image.size(), n = image[0].size(), 
        curr = 0, row, col, i, j;
    image[sr][sc] = newColor;
    pixels.emplace_back(sr, sc);
    while (curr < pixels.size())
    {
        row = pixels[curr].first;
        col = pixels[curr].second;
        ++curr;
        for (int k = 0; k < 4; ++k)
        {
            i = row + direction[k][0];
            j = col + direction[k][1];
            if (i >= 0 && j >= 0 && i < m && j < n && image[i][j] == oldColor)
            {
                image[i][j] = newColor;
                pixels.emplace_back(i, j);
            }
        }
    }
    return image;
}