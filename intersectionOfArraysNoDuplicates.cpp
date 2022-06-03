#include <vector>
#include <algorithm>

  std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) 
{
    std::sort(begin(nums1), end(nums1));
    std::sort(begin(nums2), end(nums2));

    std::vector<int> intersection;
    int p1 = 0, p2 = 0;

    while (p1 < nums1.size() && p2 < nums2.size())
    {
        if (nums1[p1] == nums2[p2])
        {
            intersection.push_back(nums1[p1]);
            ++p1;
            ++p2;
            while (p1 < nums1.size() && nums1[p1] == nums1[p1 - 1]) ++p1;
            while (p2 < nums2.size() && nums2[p2] == nums2[p2 - 1]) ++p2;
        }
        else if (nums1[p1] < nums2[p2]) { ++p1; }
        else { ++p2; }
    }
    return intersection;
}