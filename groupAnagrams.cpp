#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs)
{
    std::unordered_map<std::string, std::vector<std::string>> hashmap(strs.size());
    std::vector<std::vector<std::string>> anagrams;
    std::vector<std::string> temp = strs;
    for (int i = 0; i < temp.size(); ++i)
    {
        std::sort(temp[i].begin(), temp[i].end());
        auto result = hashmap.insert({temp[i], {strs[i]}});
        if (!result.second) { result.first->second.push_back(strs[i]); }
    }
    for (auto it : hashmap) { anagrams.push_back(it.second); }
    return anagrams;
}