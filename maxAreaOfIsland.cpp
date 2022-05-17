#include <vector>

int searchIsland(std::vector<std::vector<int>>& grid, int i, int j)
{
    std::vector<std::pair<int, int>> island;
    island.emplace_back(i, j);
    int row, col, area = 1;
    grid[i][j] = -1;

    while (!island.empty())
    {
        row = island.back().first;
        col = island.back().second;
        island.pop_back();

        if (row - 1 >= 0 && grid[row - 1][col] == 1)
        {
            island.emplace_back(row - 1, col);
            grid[row - 1][col] = -1;
            ++area;
        }
        if (row + 1 < grid.size() && grid[row + 1][col] == 1)
        {
            island.emplace_back(row + 1, col);
            grid[row + 1][col] = -1;
            ++area;
        }
        if (col - 1 >= 0 && grid[row][col - 1] == 1)
        {
            island.emplace_back(row, col - 1);
            grid[row][col - 1] = -1;
            ++area;
        }        
        if (col + 1 < grid[row].size() && grid[row][col + 1] == 1)
        {
            island.emplace_back(row, col + 1);
            grid[row][col + 1] = -1;
            ++area;
        }
    }
    return area;
}

int maxAreaOfIsland(std::vector<std::vector<int>>& grid) 
{
    int max = 0, curr = 0;
    for (int i = 0; i < grid.size(); ++i)
    {
        for (int j = 0; j < grid[i].size(); ++j)
        {
            if (grid[i][j] == 1)
            {
                curr = searchIsland(grid, i, j);
                max = curr > max ? curr : max;
            }
        }
    }
    return max;
}