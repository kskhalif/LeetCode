#include <vector>
#include <algorithm>

std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals)
{
    std::vector<std::vector<int>> answer;
    auto comp = [](const std::vector<int>& i1, const std::vector<int>& i2)
                {
                    return i1[0] != i2[0] ? i1[0] < i2[0] : i1[1] < i2[1];
                };
    std::sort(begin(intervals), end(intervals), comp);
    for (int i = 0; i < intervals.size(); ++i)
    {
        if (i + 1 == intervals.size() || intervals[i][1] < intervals[i + 1][0])
        { 
            answer.push_back(intervals[i]); 
        }
        else
        {
            intervals[i + 1][0] = intervals[i][0];
            intervals[i + 1][1] = intervals[i + 1][1] > intervals[i][1] ? 
                                  intervals[i + 1][1] : intervals[i][1];
        }
    }
    return answer;
} 