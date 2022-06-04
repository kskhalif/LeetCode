#include <unordered_map>
#include <queue>

using int_pair = std::pair<int, int>;

struct comp
{
    bool operator()(const int_pair& p1, const int_pair& p2)
    {
        return p1.second > p2.second;
    }
};

class LRUCache 
{
private:
    std::unordered_map<int, int_pair> hashmap; // (key, (value, time)) 
    std::priority_queue<int_pair, std::vector<int_pair>, comp> LRU; // (key, time)
    int max, curr = 0, time = 0;
public:
    LRUCache(int capacity)
    {
        hashmap.reserve(capacity);
        max = capacity;
    }

    int get(int key) 
    {
        auto it = hashmap.find(key);
        if (it != hashmap.end())
        {
            it->second.second = time;
            if (LRU.top().first == key)
            {
                LRU.pop();
                LRU.emplace(key, time);
            }
            ++time;
            return it->second.first;
        }
        else { return -1; }
    }

    void put(int key, int value) 
    {
        auto it = hashmap.find(key);
        if (it != hashmap.end()) 
        { 
            it->second.first = value; 
            it->second.second = time;
            if (LRU.top().first == key)
            {
                LRU.pop();
                LRU.emplace(key, time);
            }
            ++time;
        }
        else
        {
            if (curr == max)
            {
                while (LRU.top().second != hashmap[LRU.top().first].second)
                {
                    int temp = LRU.top().first;
                    LRU.pop();
                    LRU.emplace(temp, hashmap[temp].second);
                }
                hashmap.erase(LRU.top().first);
                LRU.pop();
            }
            else { ++curr; }
            hashmap.insert({key, {value, time}});
            LRU.emplace(key, time);
            ++time;
            while (LRU.top().second != hashmap[LRU.top().first].second)
            {
                int temp = LRU.top().first;
                LRU.pop();
                LRU.emplace(temp, hashmap[temp].second);
            }
        }
    }
};

/*
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */