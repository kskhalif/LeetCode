#include <vector>
#include <utility>

void reverseString(std::vector<char>& s) 
{
    int front = 0, back = (s.size() - 1);

    while (front < back)
    {
        std::swap(s[front], s[back]);
        ++front;
        --back;
    }
}