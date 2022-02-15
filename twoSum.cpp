#include <vector>

std::vector<int> twoSum(std::vector<int>& numbers, int target)
{
    std::vector<int> answer = {0,0};
    int left = 0, right = (numbers.size() - 1), sum = 0;

    while (left < right)
    {
        sum = numbers[left] + numbers[right];
        if (sum == target)
        {
            answer[0] = left + 1;
            answer[1] = right + 1;
            return answer;
        }
        else if (sum > target) { --right; }
        else { ++left; }
    }
    return answer;
}