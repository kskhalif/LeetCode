#include <string>
#include <vector>

int lengthOfLongestSubstring(std::string s)
{
    std::vector<int> iVec(95, -1);
    int start = -1, maxLength = 0;

    for (int i = 0; i != s.length(); ++i)
    {
        if (iVec[s[i] - 32] > start)
        {
            start = iVec[s[i] - 32];
        }
        iVec[s[i] - 32] = i;
        maxLength = maxLength > (i - start) ? maxLength : (i - start);
    }
    return maxLength;
}