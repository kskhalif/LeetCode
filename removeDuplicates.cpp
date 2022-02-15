#include <vector>
    
template<typename T>
void removeDuplicates(std::vector<T>& list) 
{
    if (list.size() == 0)
        return;
    if (list.size() == 1)
        return;
        
    size_t j = 0;
        
    for (size_t i = 0; i < (list.size() - 1); ++i)
        if (list[i] != list[i + 1])
            list[j++] = list[i];
              
    list[j++] = list.back();

    list.erase(list.begin() + j, list.end());
}