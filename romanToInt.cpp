#include <string>

int romanToInt(std::string s)
{
    int num = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        switch (s[i])
        {
            case 'I':
                (i < s.length() - 1 && (s[i + 1] == 'V' || s[i + 1] == 'X')) ? 
                --num : ++num;
                break;
            case 'V':
                num += 5;
                break;
            case 'X':
                (i < s.length() - 1 && (s[i + 1] == 'L' || s[i + 1] == 'C')) ?
                num -= 10 : num += 10;
                break;
            case 'L':
                num += 50;
                break;
            case 'C':
                (i < s.length() - 1 && (s[i + 1] == 'D' || s[i + 1] == 'M')) ?
                num -= 100 : num += 100;
                break;
            case 'D':
                num += 500;
                break;
            case 'M':
                num += 1000;
                break;
            default:
                break;
        }
    }
    return num;
}