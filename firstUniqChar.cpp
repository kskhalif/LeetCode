#include <string>

int firstUniqChar(std::string s) 
{
    char letters[26] = {0};
    for (auto& c : s) { ++letters[c - 'a']; }
    for (int i = 0; i < s.length(); ++i) 
    { 
        if (letters[s[i] - 'a'] == 1) { return i; } 
    }
    return -1;
}