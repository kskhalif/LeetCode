#include <vector>
#include <queue>
#include <algorithm>

// Method 2
std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k) 
{
    std::vector<std::vector<int>> heap;
    auto comp = [](const std::vector<int>& p1, const std::vector<int>& p2)
                {
                    return (p1[0]*p1[0] + p1[1]*p1[1]) < (p2[0]*p2[0] + p2[1]*p2[1]);
                };
    for (int i = 0; i < points.size(); ++i)
    {
        heap.push_back(points[i]);
        std::push_heap(begin(heap), end(heap), comp);
        if (heap.size() > k)
        {
            std::pop_heap(begin(heap), end(heap), comp);
            heap.pop_back();
        }
    }
    return heap;
}

// Method 1
struct comp
{
    bool operator()(const std::vector<int>& p1, const std::vector<int>& p2) const
    {
        return (p1[0]*p1[0] + p1[1]*p1[1]) > (p2[0]*p2[0] + p2[1]*p2[1]);
    }
};

std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k) 
{
    std::priority_queue<std::vector<int>, 
                        std::vector<std::vector<int>>, 
                        comp> heap(begin(points), end(points));
    std::vector<std::vector<int>> answer(k, std::vector<int>(2));
    for (int i = 0; i < k; ++i)
    {
        answer[i] = heap.top();
        heap.pop();
    }
    return answer;
}