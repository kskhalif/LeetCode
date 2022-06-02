#include <vector>
#include <unordered_set>

bool containsDuplicate(std::vector<int>& nums) 
{
    std::unordered_set<int> set(nums.size());
    for (const auto& num : nums) { if (!set.insert(num).second) { return true; } }
    return false;
}