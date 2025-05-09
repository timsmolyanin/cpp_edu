

#include <iostream>
#include <map>
#include <string>
#include <sstream> 

using namespace std;

void PrintAllCapitals(const map<string, string>& caps_dir);
void ChangeCapital(map<string, string>& caps_dir, const string& country, const string& new_capital);
void RenameCountry(map<string, string>& caps_dir, const string& old_country_name, const string& new_country_name);
void PrintAbout(map<string, string>& caps_dir, const string& country);


int main(){
    int cmd_cnt;
    string input_line;
    string cmd;
    int arg;
    map<string, string> capitals_directory;

    cin >> cmd_cnt;
    cin.ignore();
    for(int i = 0; i < cmd_cnt; ++i){
        getline(cin, input_line);
        istringstream iss(input_line);
        iss >> cmd;
        if(cmd == "DUMP"){
            PrintAllCapitals(capitals_directory);
        }
        else if (cmd == "CHANGE_CAPITAL"){
            string country, new_capital;
            iss >> country >> new_capital;
            ChangeCapital(capitals_directory, country, new_capital);
        }
        else if (cmd == "RENAME"){
            string old_country_name, new_country_name;
            iss >> old_country_name >> new_country_name;
            RenameCountry(capitals_directory, old_country_name, new_country_name);
        }
        else if (cmd == "ABOUT"){
            string country;
            iss >> country;
            PrintAbout(capitals_directory, country);
        }
    }
    return 0;
}

void PrintAllCapitals(const map<string, string>& caps_dir){
    if(caps_dir.size() == 0){
        cout << "There are no countries in the world" << endl;
    }
    bool tmp = true;
    for (auto items : caps_dir){
        if(!tmp){
            cout << " ";
        }
        tmp = false;
        cout << items.first << "/" << items.second;
    }
    cout << endl;
}

void ChangeCapital(map<string, string>& caps_dir, const string& country, const string& new_capital){
    if (caps_dir.count(country) == 0){
        cout << "Introduce new country " << country << " with capital " << new_capital << endl;
        caps_dir[country] = new_capital;
    }
    else if (caps_dir[country] == new_capital){
        cout << "Country " << country << " hasn't changed its capital" << endl;
    }
    else if (caps_dir[country] != new_capital){
        cout << "Country " << country << " has changed its capital from " << caps_dir[country] << " to " << new_capital << endl;
        caps_dir[country] = new_capital;
    }
}

void RenameCountry(map<string, string>& caps_dir, const string& old_country_name, const string& new_country_name){
    if (caps_dir.count(old_country_name) == 0 || caps_dir.count(new_country_name) != 0 || old_country_name == new_country_name){
        cout << "Incorrect rename, skip" << endl;
    }
    else{
        auto tmp_value = caps_dir[old_country_name];
        caps_dir.erase(old_country_name);
        caps_dir[new_country_name] = tmp_value;
        cout << "Country " << old_country_name << " with capital " << tmp_value << " has been renamed to " << new_country_name << endl;
    }
}

void PrintAbout(map<string, string>& caps_dir, const string& country){
    if (caps_dir.count(country) == 0){
        cout << "Country " << country << " doesn't exist" << endl;
    }
    else{
        cout << "Country " << country <<  " has capital " << caps_dir[country] << endl;
    }
}
