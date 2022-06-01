#include <vector>
#include <unordered_map>
#include <queue>

typedef std::pair<int, int> pair;

struct comp
{
    bool operator()(const pair& lhs, const pair& rhs) const
    {
        return lhs.second < rhs.second;
    }
};

int minSetSize(std::vector<int>& arr)
{
    std::unordered_map<int, int> hash(arr.size());
    for (int i = 0; i < arr.size(); ++i)
    {
        auto result = hash.emplace(arr[i], 1);
        if (!result.second) { ++result.first->second; } 
    }
    std::priority_queue<pair, std::vector<pair>, comp> heap(begin(hash), end(hash));
    int half = ((arr.size() % 2 == 0) ? (arr.size() / 2) : (arr.size() / 2 + 1));
    int set_size = 0;
    while (half > 0)
    {
        half -= heap.top().second;
        ++set_size;
        heap.pop();
    }
    return set_size;
}