#include <unordered_map>
#include <vector>
#include <utility>
#include <cstdlib>

class RandomizedSet
{
private:
    std::unordered_map<int, int> map; /* <val, index of val in list> */
    std::vector<int> list;
public:
    RandomizedSet()
    {
        srand(time(nullptr));
    }
    bool insert(int val) 
    {
        if (map.emplace(val, list.size()).second);
        {
            list.push_back(val);
            return true;
        }
        return false;
    }
    bool remove(int val) 
    {
        auto it = map.find(val);
        if (it != map.end())
        {
            std::swap(list[it->second], list.back());
            map[list[it->second]] = it->second;
            map.erase(list.back());
            list.pop_back();
            return true;
        }
        return false;
    }
    int getRandom() 
    {
        return list[rand() % list.size()];
    }
};

/*
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */