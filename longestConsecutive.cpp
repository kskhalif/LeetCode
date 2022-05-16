#include <vector>
#include <unordered_set>
#include <algorithm>

// Sorting(time: O(nlogn), space: O(1))
int longestConsecutive(std::vector<int>& nums) 
{
    if (nums.empty()) { return 0; }
    int curr = 1, max = 1;
    std::sort(nums.begin(), nums.end());
    for (int i = 1; i < nums.size(); ++i)
    {
        if (nums[i] - nums[i - 1] == 1) { ++curr; }
        else if (nums[i] - nums[i - 1] != 0)
        {
            max = curr > max ? curr : max;
            curr = 1;
        }
    }
    max = curr > max ? curr : max;
    return max;
}

// Hashing(time: O(n), space: O(n))
int longestConsecutive(std::vector<int>& nums) 
{
    if (nums.empty()) { return 0; }
    std::unordered_set<int> set(nums.begin(), nums.end());
    int curr = 1, max = 1, prev, next;
    for (int i = 0; i < nums.size(); ++i)
    {
        prev = nums[i] - 1;
        if (set.find(prev) == set.end())
        {
            next = nums[i] + 1;
            while (set.find(next) != set.end())
            {
                ++next;
                ++curr;
            }
            max = curr > max ? curr : max;
            curr = 1;
        }
    }
    return max;
}