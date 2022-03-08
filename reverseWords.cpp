#include <string>

std::string reverseWords(std::string s)
{
    int i = (s.length() - 1);
    while (s[i] == ' ') 
    { 
        s.pop_back();
        --i; 
    }
    while (i > 0 && s[i - 1] != ' ') { --i; }
    int newBegin = i--;
    while (i >= 0 && s[i] == ' ') { --i; }
    while (i >= 0)
    {
        while (i > 0 && s[i - 1] != ' ' ) { --i; }
        s.push_back(' ');
        while (s[i] != ' ') 
        { 
            s.push_back(s[i]); 
            ++i;
        }
        --i;
        while (i >= 0 && s[i] != ' ') { --i; }
        while (i >= 0 && s[i] == ' ') { --i; }
    }
    s.erase(0, newBegin);
    return s;
}