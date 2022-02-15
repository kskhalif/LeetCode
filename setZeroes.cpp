#include <vector>
#include <algorithm>

template<typename T>
void setZeroes(std::vector<std::vector<T>>& matrix) 
{
    if (matrix.empty()) { return; }

    size_t m = matrix.size();
    size_t n = matrix[0].size();
    bool setRowToZeroes = false;
    std::vector<char> setColumnToZero;
    setColumnToZero.reserve(n);
    setColumnToZero.resize(n);
    std::fill(setColumnToZero.begin(), setColumnToZero.end(), '0');
    
    for (size_t i = 0; i < m; ++i)
    {
        setRowToZeroes = false;

        for (size_t j = 0; j < n; ++j)
        {
            if (matrix[i][j] == 0 && setColumnToZero[j] == '0') 
            {
                setColumnToZero[j] = '1';
                setRowToZeroes = true;                
                for (size_t k = 0; k < m; ++k)
                {
                    if (matrix[k][j] == 0 && k > i)
                    {
                        matrix[k][j] = 1;
                    }
                    else
                    {
                        matrix[k][j] = 0;
                    }
                }  
            }
            else if (matrix[i][j] != 0 && setColumnToZero[j] == '1')
            {
                matrix[i][j] = 0;
                setRowToZeroes = true;
            }
        }
        if (setRowToZeroes)
        {
            for (size_t k = 0; k < n; ++k)
            {
                matrix[i][k] = 0;
            }
        }
    }
}