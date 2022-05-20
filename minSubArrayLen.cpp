#include <vector>

int minSubArrayLen(int target, std::vector<int>& nums)
{
    int left = 0, sum = 0, answer = (nums.size() + 1);

    for (int i = 0; i < nums.size(); ++i)
    {
        sum += nums[i];
        while (sum >= target)
        {
            answer = answer < (i + 1 - left) ? answer : (i + 1 - left);
            sum -= nums[left];
            ++left;
        }
    }
    return (answer != (nums.size() + 1) ? answer : 0);
}