#include <string>
#include <unordered_map>
#include <map>
#include <functional>

using time_map = std::map<int, std::string, std::greater<int>>;

class TimeMap
{
private:
    std::unordered_map<std::string, time_map> hashmap;
public:
    TimeMap() {}
    
    void set(std::string key, std::string value, int timestamp)
    {
        auto it = hashmap.find(key);
        if (it == hashmap.end())
        {
            hashmap.emplace(key, time_map({{timestamp, value}}));
        }
        else
        {
            it->second.emplace(timestamp, value);
        }
    }
    
    std::string get(std::string key, int timestamp) 
    {
        auto it1 = hashmap.find(key);
        if (it1 != hashmap.end())
        {
            auto it2 = it1->second.lower_bound(timestamp);
            if (it2 != it1->second.end())
            {
                return it2->second;
            }
        }
        return "";
    }
};

/*
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * std::string param_2 = obj->get(key,timestamp);
 */