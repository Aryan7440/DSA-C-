#include <bits/stdc++.h>
using namespace std;
class UndergroundSystem
{
public:
    unordered_map<int, pair<string, int>> time;
    unordered_map<string, unordered_map<string, pair<int, int>>> avg;

    UndergroundSystem()
    {
    }

    void checkIn(int id, string stationName, int t)
    {
        time[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t)
    {
        avg[time[id].first][stationName].second++;
        avg[time[id].first][stationName].first += (t - time[id].second);
        time.erase(id);
    }

    double getAverageTime(string startStation, string endStation)
    {
        return (double)avg[startStation][endStation].first / avg[startStation][endStation].second;
    }
};
int main()
{

    //  Your UndergroundSystem object will be instantiated and called as such:
    // UndergroundSystem *obj = new UndergroundSystem();
    // obj->checkIn(id, stationName, t);
    // obj->checkOut(id, stationName, t);
    // double param_3 = obj->getAverageTime(startStation, endStation);
}