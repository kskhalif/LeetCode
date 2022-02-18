#include <vector>
    
template<typename T>
void removeDuplicates(std::vector<T>& list) 
{
    if (nums.size() <= 1) 
        return;
    
    size_t k = 0;
    
    for (size_t i = 0; i < nums.size() - 1; ++i)
        if (nums[i] != nums[i + 1])
            nums[k++] = nums[i];
                
    nums[k++] = nums.back();
    
    nums.erase(nums.begin() + k, nums.end());
}