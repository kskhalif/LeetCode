#include <bits/stdc++.h>
using namespace std;
    
int removeDuplicates(vector<int>& nums) 
{
    if (nums.empty()) return 0;
    if (nums.size() == 1) return 1;

    for (int i = nums.size() - 1; i > 0; i--)
    {
        if (nums[i] == nums[i - 1])
        {
            for (int j = i; j < nums.size() - 1; j++)
                swap(nums[j], nums[j+1]);
            nums.pop_back();       
        }
    }
    return nums.size();
}

int removeDuplicates(vector<int>& nums) 
{
    if (nums.size() == 0)
        return 0;
        
    int k = 0;
        
    for (int i = 0; i < nums.size() - 1; i++)
        if (nums[i] != nums[i+1])
            nums[k++] = nums[i];
              
    nums[k++] = nums[nums.size()-1];
    return k;
}