class UndergroundSystem {
public:
    
    map<int,pair<string,int>>mp1;
    map< string, pair<double,int> >mp2;
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        mp1[id]= {stationName, t};
    }
    
    void checkOut(int id, string des, int t) {
        auto it = mp1[id];
        mp1.erase(id);
        string source = it.first;
        int start =  it.second;
        string path = source+"_"+des;
        mp2[path].first+=(t-start);
        mp2[path].second+=1;

        
    }
    
    double getAverageTime(string startStation, string endStation) {
        string path=startStation+"_"+endStation;
        auto route=mp2[path];
        return route.first/(double)route.second;

    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */