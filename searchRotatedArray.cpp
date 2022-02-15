#include <vector>

template<typename T>
T searchRotatedArray(std::vector<T>& nums, T target) 
{
    if (nums.empty()) { return -1; }
    if (nums.size() == 1) { return (nums[0] == target ? 0 : -1); }
    if (nums.size() == 2) 
    {
        if (nums[0] == target) { return 0; }
        else if (nums[1] == target) { return 1; }
        else { return -1; }
    }
    int l = 0, r = (nums.size() - 1), m = (l + ((r - l) / 2));
    while (l <= r)
    {
        if (nums[m] == target) { return m; }

        else if (nums[m] < target) 
        { 
            if (target <= nums.back()) { l = m + 1; }
            else
            {
                if (nums[m] > nums.back()) { l = m + 1; }
                else { r = m - 1; }
            }
        }
        else
        {
            if (target > nums.back()) { r = m - 1; }
            else
            {
                if (nums[m] > nums.back()) { l = m + 1; }
                else { r = m - 1; }
            }
        }
        m = (l + ((r - l) / 2));
    }
    return -1;
}