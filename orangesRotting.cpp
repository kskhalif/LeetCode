#include <vector>

class RottingOranges
{
private:
    std::vector<std::pair<int, int>> rottenOranges;
    int direction[4][2] = {{1,0},{-1, 0},{0,1},{0,-1}};
    std::vector<std::vector<int>>* gridPtr;
    int m, n,row, col, i, j, numEmpty = 0, numRotten = 0, index = 0, minutes = 0;
public:
    RottingOranges() {}
    RottingOranges(std::vector<std::vector<int>>& grid)
    {
        m = grid.size();
        n = grid[0].size();
        gridPtr = &grid;
    }
    void findRottenOranges()
    {
        for (int k = 0; k < m; ++k)
        {
            for (int l = 0; l < n; ++l)
            {
                if (gridPtr->at(k).at(l) == 2) { rottenOranges.emplace_back(k, l); }
                else if (gridPtr->at(k).at(l) == 0) { ++numEmpty; }
            }
        }
    }
    void freshToRotten()
    {
        while (rottenOranges.size() > numRotten)
        {
            numRotten = rottenOranges.size();
            for (index; index < numRotten; ++index)
            {
                row = rottenOranges[index].first;
                col = rottenOranges[index].second;
                for (int k = 0; k < 4; ++k)
                {
                    i = row + direction[k][0];
                    j = col + direction[k][1];
                    if (i >= 0 && j >= 0 && 
                        i < m && j < n &&
                        gridPtr->at(i).at(j) == 1)
                    {
                        gridPtr->at(i).at(j) = 2;
                        rottenOranges.emplace_back(i, j);
                    }
                }
            }
            if (numRotten < rottenOranges.size()) { ++minutes; }
        }
    }
    int timeElapsed() { return (numRotten + numEmpty == m*n ? minutes : -1); }
};

int orangesRotting(std::vector<std::vector<int>>& grid) 
{
    RottingOranges obj(grid);
    obj.findRottenOranges();
    obj.freshToRotten();
    return obj.timeElapsed();
}