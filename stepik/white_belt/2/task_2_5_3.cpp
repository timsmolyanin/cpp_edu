

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream> 
#include <algorithm>

using namespace std;

void PrintAllBuses(const vector<map<string, vector<string>>>& bus_dir);
vector<string> FindBusesForStop(const vector<map<string, vector<string>>>& bus_dir, const string& stop_name);
void FindStopsForBus(const vector<map<string, vector<string>>>& bus_dir, const string& bus);
void PrintBusesForStop(const vector<string>& buses_list, const string& empty_list_phraze);


int main(){
    int cmd_cnt;
    string input_line;
    string cmd;
    int arg;
    vector<map<string, vector<string>>> buses_directory;

    cin >> cmd_cnt;
    cin.ignore();
    for(int i = 0; i < cmd_cnt; ++i){
        getline(cin, input_line);
        istringstream iss(input_line);
        iss >> cmd;
        if(cmd == "ALL_BUSES"){
            PrintAllBuses(buses_directory);
        }
        else if (cmd == "NEW_BUS"){
            int stop_cnt;
            vector<string> stop_names;
            map<string, vector<string>> bus_and_stops;
            string bus_num, tmp_stop_name;
            iss >> bus_num >> stop_cnt;
            for (int i = 0; i < stop_cnt; ++i){
                iss >> tmp_stop_name;
                stop_names.push_back(tmp_stop_name);
            }
            bus_and_stops[bus_num] = stop_names;
            buses_directory.push_back(bus_and_stops);
        }
        else if (cmd == "BUSES_FOR_STOP"){
            string stop_name;
            iss >> stop_name;
            vector<string> buses; 
            buses = FindBusesForStop(buses_directory, stop_name);
            PrintBusesForStop(buses, "No stop");
        }
        else if (cmd == "STOPS_FOR_BUS"){
            string bus;
            iss >> bus;
            FindStopsForBus(buses_directory, bus);
        }
    }
    return 0;
}

void PrintAllBuses(const vector<map<string, vector<string>>>& bus_dir){
    if (bus_dir.size() == 0){
        cout << "No buses" << endl;
    }
    else{
        map<string, vector<string>> combined_map;

        for (const auto& dict : bus_dir) {
            for (const auto& items : dict) {
                // Если ключ уже существует, объединяем векторы
                combined_map[items.first].insert(combined_map[items.first].end(), items.second.begin(), items.second.end());
            }
        }
            
        for (auto items : combined_map){
            cout << "Bus " << items.first << ": ";
            bool tmp = true;
            for (auto stop_name : items.second){
                if(!tmp){
                    cout << " ";
                }
                tmp = false;
                cout << stop_name;
            }
            cout << endl;
        }
    }
}

vector<string> FindBusesForStop(const vector<map<string, vector<string>>>& bus_dir, const string& stop_name){
    vector<string> buses = {};
    for (auto bus : bus_dir){
        for (auto items : bus){
           if (count(items.second.begin(), items.second.end(), stop_name) > 0){
            buses.push_back(items.first);
           }
        }
    }
    return buses;
}

void PrintBusesForStop(const vector<string>& buses_list, const string& empty_list_phraze){
    if (buses_list.size() == 0){
        cout << empty_list_phraze << endl;
    }
    else{
        bool tmp = true;
        for (auto bus : buses_list){
            if(!tmp){
                cout << " ";
            }
            tmp = false;
            cout << bus;
        }
        cout << endl;
    }
}

void FindStopsForBus(const vector<map<string, vector<string>>>& bus_dir, const string& bus){
    // Stop stop: bus1 bus2 ...
    bool is_bus_exist = false;
    for (auto bus_name : bus_dir){
        if (bus_name.count(bus) > 0){
            is_bus_exist = true;
            vector<string>& stops = bus_name[bus];
            for (auto stop : stops){
                vector<string> buses = {};
                cout << "Stop " << stop << ": ";
                buses = FindBusesForStop(bus_dir, stop);
                buses.erase(
                    remove(buses.begin(), buses.end(), bus), 
                    buses.end()
                );
                PrintBusesForStop(buses, "no interchange");
            }
        }
    }
    if(!is_bus_exist){
        cout << "No bus" << endl;
    }
        
}