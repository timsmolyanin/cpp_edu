#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

enum class QueryType {
    NewBus,
    BusesForStop,
    StopsForBus,
    AllBuses
};

struct Query {
    QueryType type;
    string bus;
    string stop;
    vector<string> stops;
};

istream& operator>>(istream& is, Query& q) {
    string operation_code;
    is >> operation_code;

    if (operation_code == "NEW_BUS") {
        q.type = QueryType::NewBus;
        is >> q.bus;
        int stop_count;
        is >> stop_count;
        q.stops.resize(stop_count);
        for (string& stop : q.stops) {
            is >> stop;
        }
    } else if (operation_code == "BUSES_FOR_STOP") {
        q.type = QueryType::BusesForStop;
        is >> q.stop;
    } else if (operation_code == "STOPS_FOR_BUS") {
        q.type = QueryType::StopsForBus;
        is >> q.bus;
    } else if (operation_code == "ALL_BUSES") {
        q.type = QueryType::AllBuses;
    }

    return is;
}

struct BusesForStopResponse {
    vector<string> buses;
};

ostream& operator<<(ostream& os, const BusesForStopResponse& r) {
    if (r.buses.empty()) {
        os << "No stop";
    } else {
        bool first = true;
        for (const auto& bus : r.buses) {
            if (!first) {
                os << " ";
            }
            first = false;
            os << bus;
        }
    }
    return os;
}

struct StopsForBusResponse {
    vector<pair<string, vector<string>>> stops;
};

ostream& operator<<(ostream& os, const StopsForBusResponse& r) {
    if (r.stops.empty()) {
        os << "No bus";
    } else {
        bool first_line = true;
        for (const auto& item : r.stops) {
            if (!first_line) {
                os << '\n';
            }
            first_line = false;
            os << "Stop " << item.first << ": ";
            if (item.second.empty()) {
                os << "no interchange";
            } else {
                bool first_bus = true;
                for (const auto& bus : item.second) {
                    if (!first_bus) {
                        os << " ";
                    }
                    first_bus = false;
                    os << bus;
                }
            }
        }
    }
    return os;
}

struct AllBusesResponse {
    map<string, vector<string>> buses_to_stops;
};

ostream& operator<<(ostream& os, const AllBusesResponse& r) {
    if (r.buses_to_stops.empty()) {
        os << "No buses";
    } else {
        bool first_bus = true;
        for (const auto& item : r.buses_to_stops) {
            if (!first_bus) {
                os << '\n';
            }
            first_bus = false;
            os << "Bus " << item.first << ": ";
            bool first_stop = true;
            for (const string& stop : item.second) {
                if (!first_stop) {
                    os << " ";
                }
                first_stop = false;
                os << stop;
            }
        }
    }
    return os;
}

class BusManager {
private:
    map<string, vector<string>> buses_to_stops;
    map<string, vector<string>> stops_to_buses;

public:
    void AddBus(const string& bus, const vector<string>& stops) {
        buses_to_stops[bus] = stops;
        for (const string& stop : stops) {
            stops_to_buses[stop].push_back(bus);
        }
    }

    BusesForStopResponse GetBusesForStop(const string& stop) const {
        BusesForStopResponse response;
        if (stops_to_buses.count(stop)) {
            response.buses = stops_to_buses.at(stop);
        }
        return response;
    }

    StopsForBusResponse GetStopsForBus(const string& bus) const {
        StopsForBusResponse response;
        if (buses_to_stops.count(bus)) {
            for (const string& stop : buses_to_stops.at(bus)) {
                vector<string> buses;
                for (const string& other_bus : stops_to_buses.at(stop)) {
                    if (other_bus != bus) {
                        buses.push_back(other_bus);
                    }
                }
                response.stops.emplace_back(stop, buses);
            }
        }
        return response;
    }

    AllBusesResponse GetAllBuses() const {
        AllBusesResponse response;
        response.buses_to_stops = buses_to_stops;
        return response;
    }
};

int main() {
    int query_count;
    Query q;

    cin >> query_count;

    BusManager bm;
    for (int i = 0; i < query_count; ++i) {
        cin >> q;
        switch (q.type) {
            case QueryType::NewBus:
                bm.AddBus(q.bus, q.stops);
                break;
            case QueryType::BusesForStop:
                cout << bm.GetBusesForStop(q.stop) << endl;
                break;
            case QueryType::StopsForBus:
                cout << bm.GetStopsForBus(q.bus) << endl;
                break;
            case QueryType::AllBuses:
                cout << bm.GetAllBuses() << endl;
                break;
        }
    }

    return 0;
}