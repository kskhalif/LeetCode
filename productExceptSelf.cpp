#include <vector>
#include <algorithm>

std::vector<int> productExceptSelf(std::vector<int>& nums) 
{
    std::vector<int> answer;
    int product = 1;
    answer.reserve(nums.size());
    answer.resize(nums.size());
    std::fill(begin(answer), end(answer), 1);

    for (int i = 1; i < nums.size(); ++i)
    {
        answer[i] *= nums[i - 1] * answer[i - 1];
    }
    for (int i = (nums.size() - 2); i >= 0; --i)
    {
        product *= nums[i + 1];
        answer[i] *= product;
    }
    return answer;
}   