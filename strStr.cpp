#include <string>
#include <vector>

/*** Knuth-Morris-Pratt Algorithm ***/
int strStr(std::string haystack, std::string needle) 
{
    if (needle.empty()) { return 0; }
    if (needle.length() > haystack.length()) { return -1; }

    std::vector<int> prefixTable(needle.length(), 0);

    for (int right = 1, left = 0; right < prefixTable.size(); ++right)
    {
        if (needle[right] == needle[left])
        {
            prefixTable[right] = ++left > prefixTable[right] ? left : prefixTable[right];
        }
        else if (left > 0 && right + 1 != prefixTable.size())
        {
            right -= left;
            left = 0;
        }
    }

    int i = 0, j = 0, start = 0, diff = haystack.size() - needle.size();

    while (start <= diff)
    {
        if (j == needle.size())
        {
            return start;
        }
        else if (haystack[i] == needle[j])
        {
            ++i;
            ++j;
        }
        else
        {
            if (j == 0) 
            { 
                ++start;
                i = start;
            }
            else 
            { 
                j = prefixTable[j - 1];
                start = i - j;
            }
        }
    }
    return -1;
}

/*** Rabin-Karp Algorithm ***/
int strStr(std::string haystack, std::string needle) 
{
    if (needle.empty()) { return 0; }
    if (needle.length() > haystack.length()) { return -1; }

    uint64_t target = 0, window = 0, left = 0, right = 0, multiplier = 1;

    for (; right < needle.size(); ++right)
    {
        target = 2 * target + needle[right];
        window = 2 * window + haystack[right];
        multiplier *= 2;
    }
    if (window == target) { return left; }
    multiplier /= 2;

    for (; right < haystack.size(); ++right)
    {
        window -= haystack[left] * multiplier;
        window *= 2;
        window += haystack[right];
        ++left;
        if (window == target) { return left; }
    }
    return -1;
}

/*** Brute-Force Algorithm ***/
int strStr(std::string haystack, std::string needle) 
{
    if (needle.empty()) { return 0; }
    if (needle.length() > haystack.length()) { return -1; }

    uint64_t i = 0, j = 0, start = 0;
    int64_t diff = haystack.size() - needle.size();

    while (start <= diff)
    {
        if (j == needle.size())
        {
            return start;
        }
        else if (haystack[i] == needle[j])
        {
            ++i;
            ++j;
        }
        else
        {
            ++start;
            i = start;
            j = 0;
        }
    }
    return -1;
}