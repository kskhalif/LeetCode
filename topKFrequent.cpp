#include <vector>
#include <queue>
#include <unordered_map>

typedef std::pair<int, int> pair;

struct comp
{
    bool operator()(const pair& lhs, const pair& rhs) const
    {
        return lhs.second < rhs.second;
    }
};

std::vector<int> topKFrequent(std::vector<int>& nums, int k) 
{
    std::unordered_map<int, int> hash(nums.size());
    for (int i = 0; i < nums.size(); ++i)
    {
        auto result = hash.emplace(nums[i], 1);
        if (!result.second) { ++result.first->second; } 
    }
    std::priority_queue<pair, std::vector<pair>, comp> heap(begin(hash), end(hash));
    std::vector<int> answer(k);
    for (int i = 0; i < k; ++i)
    {
        answer[i] = heap.top().first;
        heap.pop();
    }
    return answer;
}