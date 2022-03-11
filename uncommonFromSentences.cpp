#include <vector>
#include <string>
#include <map>
#include <utility>

std::vector<std::string> uncommonFromSentences(std::string s1, std::string s2) 
{
    std::map<std::string, int> words;
    std::vector<std::string> uncommonWords;
    int i = 0, j = 0, count = 0;

    while (i < s1.length() || j < s2.length())
    {
        ++count;
        std::string temp;
        if (count % 2 == 1 && i < s1.length())
        {
            while (i < s1.length() && s1[i] != ' ')
            {
                temp.push_back(s1[i]);
                ++i;
            }
            ++i;
        }
        else if (count % 2 == 0 && j < s2.length())
        {
            while (j < s2.length() && s2[j] != ' ')
            {
                temp.push_back(s2[j]);
                ++j;
            }
            ++j;
        }
        if (temp.length())
        {
            auto result = words.insert({temp, uncommonWords.size()});
            if (result.second)
            {
                uncommonWords.push_back(temp);
            }
            else if (result.first->second != -1)
            {
                int n = (uncommonWords.size() - 1);
                words[uncommonWords[n]] = result.first->second;
                std::swap(uncommonWords[result.first->second], uncommonWords[n]);
                uncommonWords.pop_back();
                result.first->second = -1;
            }
        } 
    }
    return uncommonWords;
}