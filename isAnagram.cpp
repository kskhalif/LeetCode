#include <string>
#include <vector>

bool isAnagram(std::string s, std::string t) 
{
    if (s.length() != t.length()) { return false; }
    std::vector<std::vector<int>> freq(2, std::vector<int>(26, 0));
    for (int i = 0; i < s.length(); ++i)
    {
        ++freq[0][s[i] - 'a'];
        ++freq[1][t[i] - 'a'];
    }
    for (int i = 0; i < 26; ++i)
    {
        if (freq[0][i] != freq[1][i]) { return false; }
    }
    return true;
}