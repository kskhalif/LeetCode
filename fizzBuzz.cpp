#include <vector>
#include <string>

std::vector<std::string> fizzBuzz(int n) 
{
    std::vector<std::string> answer(n);

    for (int i = 1; i <= n; ++i)
    {
        if (i % 3 == 0 && i % 5 == 0)
        {
            answer[i - 1] = "FizzBuzz";
        }
        else if (i % 3 == 0)
        {
            answer[i - 1] = "Fizz";
        }
        else if (i % 5 == 0)
        {
            answer[i - 1] = "Buzz";
        }
        else
        {
            answer[i - 1] = std::to_string(i);
        }
    }
    return answer;
}