#include <vector>
#include <map>

int subarraySum(std::vector<int>& nums, int k)
{
    std::map<int, int> map; /* <index, sum> */
    int answer = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        for (auto& it : map)
        {
            it.second += nums[i];
            if (it.second == k)
            {
                ++answer;
                map.erase(it.first);
            }
        }
        if (nums[i] == k) { ++answer; }
        else { map.emplace(i, nums[i]); }
    }
    return answer;
}