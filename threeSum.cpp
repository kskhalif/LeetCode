#include <vector>
#include <algorithm>

std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
{
    std::vector<std::vector<int>> triplets;
    int i = 0, left, right, target, sum;
    std::sort(begin(nums), end(nums));
    while (i < nums.size() && nums[i] <= 0)
    {
        target = (nums[i] * -1);
        left = i + 1;
        right = (nums.size() - 1);
        while (left < right)
        {
            sum = nums[left] + nums[right];
            if (sum < target) { ++left; }
            else if (sum > target) { --right; }
            else /* (sum == target) */
            {
                triplets.push_back({ nums[i], nums[left], nums[right] });
                ++left;
                --right;
                while (left < right && nums[left] == nums[left - 1]) { ++left; }
                while (left < right && nums[right] == nums[right + 1]) { --right; }
            }
        }
        ++i;
        while (i < nums.size() && nums[i] == nums[i - 1]) { ++i; }
    }
    return triplets;
}

std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
{
    std::vector<std::vector<int>> triplets;
    int left = 0, right = (nums.size() - 1), temp;
    std::sort(begin(nums), end(nums));
    while (left < (right - 1))
    {
        if (nums[left] + nums[right] < 0)
        {
            if (nums[right - 1] > 0)
            {
                if (nums[left] + nums[right] + nums[right - 1] == 0)
                {
                    triplets.push_back({nums[left], nums[right], nums[right - 1]});
                }
            }
            else if (nums[right - 1] < 0) { break; }
            ++left;
        }
        else if (nums[left] + nums[right] > 0)
        {
            if (nums[left + 1] < 0)
            {
                if (nums[left] + nums[left + 1] + nums[right] == 0)
                {
                    triplets.push_back({nums[left], nums[left + 1], nums[right]});
                }
            }
            else if (nums[left + 1] > 0) { break; }
            --right;
        }
        else /* (nums[left] + nums[right] == 0) */
        {
            temp = (left + 1);
            while (nums[temp] < 0) { ++temp; }
            if (nums[temp] == 0)
            { 
                triplets.push_back({nums[left], nums[temp], nums[right]});
            }
            /* UNFINISHED */
        }
    }
    return triplets;
} 