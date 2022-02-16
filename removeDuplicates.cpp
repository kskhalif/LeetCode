#include <vector>
#include <utility>
    
template<typename T>
void removeDuplicates(std::vector<T>& list) 
{
    if (nums.size() <= 1) 
        return;

    for (int i = (nums.size() - 1); i > 0; --i)
    {
        if (nums[i] == nums[i - 1])
        {
            for (int j = i; j < (nums.size() - 1); ++j)
                std::swap(nums[j], nums[j + 1]);
            nums.pop_back();       
        }
    }
}