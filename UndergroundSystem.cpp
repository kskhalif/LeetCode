#include <string>
#include <vector>
#include <unordered_map>

class UndergroundSystem
{
private:
    std::unordered_map<int, std::pair<std::string, int>> customers;
    std::unordered_map<std::string, std::pair<double, double>> stations;
public:
    UndergroundSystem() {}

    void checkIn(int id, std::string stationName, int t) 
    {
        customers.emplace(id, std::pair<std::string, int>(stationName, t));
    }
    
    void checkOut(int id, std::string stationName, int t) 
    {
        auto it1 = customers.find(id);
        std::string stationNames = it1->second.first + " " + stationName;
        int travel_time = t - it1->second.second;
        customers.erase(it1);
        
        auto it2 = stations.find(stationNames);
        if (it2 != stations.end()) 
        { 
            it2->second.first += travel_time; 
            ++it2->second.second;
            return;
        }
        stations.emplace(stationNames, std::pair<double, double>(travel_time, 1));
    }
    
    double getAverageTime(std::string startStation, std::string endStation) 
    {
        auto it = stations.find(startStation + " " + endStation);
        return (it->second.first / it->second.second);
    }
};

/*
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */