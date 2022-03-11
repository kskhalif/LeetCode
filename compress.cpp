#include <vector>
#include <string>

int compress(std::vector<char>& chars)
{
    if (chars.size() == 1) return 1;
    int end = chars.size();
    for (int i = 1; i < end; ++i)
    {
        int count = 1;
        while (i < end && chars[i - 1] == chars[i])
        {
            ++i;
            ++count;
        }
        chars.push_back(chars[i - 1]);
        if (count > 1)
        {
            std::string num = std::to_string(count);
            for (int i = 0; i < num.size(); ++i)
                chars.push_back(num[i]);
        }
        if (i + 1 == end) chars.push_back(chars[i]);
    }
    chars.erase(chars.begin(), chars.begin() + end);
    return chars.size();
}