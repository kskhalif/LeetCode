#include <vector>
#include <utility>

template<typename T>
void rotate(std::vector<T>& nums, int k)
{
    if (nums.empty()) { return; }
    k %= nums.size();
    if (k == 0 || nums.size() <= 1) { return; }
    if (nums.size() == 2) { std::swap(nums[0], nums[1]); return; }

    if (k == (nums.size() - 1)) 
    { 
        for (int i = 0; i < k; ++i) 
            { std::swap(nums[i], nums[i + 1]); }
        return; 
    }
    if (k == 1)
    {
        for (int i = (nums.size() - 1); i > 0; --i)
            { std::swap(nums[i], nums[i - 1]); }
        return;
    }

    int left = 0;
    int right = (nums.size() - k);
    int notRotatedYet = nums.size();
    int rotated = 0;

    while (notRotatedYet > 1)
    {
        while (right < nums.size())
        {
            std::swap(nums[left], nums[right]);
            ++left;
            ++right;
            ++rotated;
        }
        if (rotated % notRotatedYet == 0) { return; }
        notRotatedYet -= rotated;
        right = (nums.size() - (rotated % notRotatedYet));
        rotated = 0;
    }
}