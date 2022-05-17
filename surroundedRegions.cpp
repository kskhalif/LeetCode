#include <vector>

void flip(std::vector<std::vector<char>>& board, 
          std::vector<std::pair<int, int>>& dead_ends, int i, int j)
{
    std::vector<std::pair<int, int>> region;
    region.emplace_back(i, j);
    board[i][j] = '?';
    int curr = 0, row, col;
    bool surrounded = true;

    while (curr < region.size())
    {
        row = region[curr].first;
        col = region[curr].second;
        ++curr;

        if (board[row - 1][col] == 'O')
        {
            if (row - 1 == 0) {  surrounded = false; }
            else 
            { 
                region.emplace_back(row - 1, col); 
                board[row - 1][col] = '?'; 
            }
        }
        if (board[row + 1][col] == 'O')
        {
            if (row + 1 == board.size() - 1) { surrounded = false; }
            else 
            { 
                region.emplace_back(row + 1, col); 
                board[row + 1][col] = '?';
            }
        }
        if (board[row][col - 1] == 'O')
        {
            if (col - 1 == 0) { surrounded = false; }
            else 
            { 
                region.emplace_back(row, col - 1); 
                board[row][col - 1] = '?';
            }
        }
        if (board[row][col + 1] == 'O')
        {
            if (col + 1 == board[row].size() - 1) { surrounded = false; }
            else 
            { 
                region.emplace_back(row, col + 1); 
                board[row][col + 1] = '?';
            }
        }
    }
    if (surrounded)
    {
        for (int k = 0; k < region.size(); ++k)
        {
            board[region[k].first][region[k].second] = 'X';
        }
    }
    else
    {
        dead_ends.insert(dead_ends.end(), region.begin(), region.end());
    }
}

void solve(std::vector<std::vector<char>>& board) 
{
    std::vector<std::pair<int, int>> dead_ends;    
    for (int i = 1; i < board.size() - 1; ++i)
    {
        for (int j = 1; j < board[i].size() - 1; ++j)
        {
            if (board[i][j] == 'O') { flip(board, dead_ends, i, j); }
        }
    }
    for (int k = 0; k < dead_ends.size(); ++k)
    {
        board[dead_ends[k].first][dead_ends[k].second] = 'O';
    }
}