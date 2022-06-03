#include <string>
#include <vector>
#include <unordered_map>

bool isAlienSorted(std::vector<std::string>& words, std::string order) 
{
    std::unordered_map<char, int> dict(52);
    int j, k;
    bool sorted = true;
    for (int i = 0; i < 26; ++i)
    {
        dict.emplace(order[i], i);
    }
    for (int i = 1; i < words.size(); ++i)
    {
        j = 0, k = 0;
        while (j < words[i - 1].length() && k < words[i].length())
        {
            if (dict[words[i - 1][j]] < dict[words[i][k]]) { break; }
            if (dict[words[i - 1][j]] > dict[words[i][k]]) { return false; }
            if (dict[words[i - 1][j]] == dict[words[i][k]]) { ++j; ++k; }
        }
        if (k == words[i].length() && j < words[i - 1].length()) { return false; }
    }
    return true;
}