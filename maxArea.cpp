#include <vector>

template<typename T>
T maxArea(std::vector<T>& height)
{
    if (height.size() <= 1) { return 0; }
    int left = 0, right = (height.size() - 1), max = 0, curr = 0;
    while (left != right)
    {
        curr = (right - left) * (height[left] < height[right] ? 
                                 height[left] : height[right]);
        if (curr > max) { max = curr; }
        height[left] < height[right] ? ++left : --right;
    }
    return max;
}