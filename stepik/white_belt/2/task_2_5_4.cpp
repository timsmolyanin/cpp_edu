

#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main(){
    int cmd_cnt;
    map<vector<string>, int> buses_routes;
    int bus_route = 0;
    cin >> cmd_cnt;
    cin.ignore();
    for(int i = 0; i < cmd_cnt; ++i){
        int stop_cnt; cin >> stop_cnt;
        vector<string> stop_names;
        for (int j = 0; j < stop_cnt; ++j){
            string tmp_stop_name; cin >> tmp_stop_name;
            stop_names.push_back(tmp_stop_name);
        }
        if (buses_routes.count(stop_names) == 0){
            buses_routes[stop_names] = ++bus_route;
            cout << "New bus " << buses_routes[stop_names] << endl;
        }
        else{
            cout << "Already exists for " << buses_routes[stop_names] << endl;
        }
    }
    return 0;
}
