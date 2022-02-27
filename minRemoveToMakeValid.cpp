#include <vector>
#include <string>

std::string minRemoveToMakeValid(std::string s)
{
    std::vector<int> indices;

    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '(') 
        {
            indices.push_back(i);                
        }
        else if (s[i] == ')')
        {
            if (indices.size()) 
            {
                indices.pop_back();
            }
            else 
            { 
                s.erase(i, 1);
                --i;
            }
        }
    }
    for (int i = 0; i < indices.size(); ++i)
    {
        s.erase((indices[i] - i), 1);
    }
    return s;
}