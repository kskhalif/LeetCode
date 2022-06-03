#include <vector>
#include <algorithm>

int missingNumber(std::vector<int>& nums) 
{
    int sum_ideal = nums.size(), sum_actual = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        sum_ideal += i;
        sum_actual += nums[i];
    }
    return (sum_ideal - sum_actual);
}