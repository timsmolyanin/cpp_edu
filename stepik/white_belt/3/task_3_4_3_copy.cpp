#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream> 
#include <map>
#include <functional>

using namespace std;

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        dfn[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        dln[year] = last_name;
    }
    
    string GetFullName(int year) {
        string fn = GetName(year, dfn);
        string ln = GetName(year, dln);
        
        if (fn.empty() && ln.empty()) return "Incognito";
        if (fn.empty()) return ln + " with unknown first name";
        if (ln.empty()) return fn + " with unknown last name";
        return fn + " " + ln;
    }

    string GetFullNameWithHistory(int year) {
        vector<string> fn_history = GetHistory(year, dfn);
        vector<string> ln_history = GetHistory(year, dln);
        
        string fn = FormatName(fn_history);
        string ln = FormatName(ln_history);
        
        if (fn.empty() && ln.empty()) return "Incognito";
        if (fn.empty()) return ln + " with unknown first name";
        if (ln.empty()) return fn + " with unknown last name";
        return fn + " " + ln;
    }

private:
    map<int, string, greater<int>> dfn, dln;

    string GetName(int year, const map<int, string, greater<int>>& m) {
        auto it = m.lower_bound(year);
        return it != m.end() ? it->second : "";
    }

    vector<string> GetHistory(int year, const map<int, string, greater<int>>& m) {
        vector<string> result;
        string last;
        for (const auto& entry : m) {
            if (entry.first > year) continue;
            if (entry.second != last) {
                result.push_back(entry.second);
                last = entry.second;
            }
        }
        return result;
    }

    string FormatName(const vector<string>& history) {
        if (history.empty()) return "";
        if (history.size() == 1) return history[0];
        
        string current = history[0];
        vector<string> prev;
        for (size_t i = 1; i < history.size(); ++i) {
            if (history[i] != current) {
                prev.push_back(history[i]);
            }
        }
        
        if (prev.empty()) return current;
        
        ostringstream oss;
        oss << current << " (";
        for (size_t i = 0; i < prev.size(); ++i) {
            if (i > 0) oss << ", ";
            oss << prev[i];
        }
        oss << ")";
        return oss.str();
    }
};

int main() {
    // Тестовые примеры из задания остаются без изменений
    Person person;
  
    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }
    
    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }
    
    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }
    
    person.ChangeFirstName(1990, "Polina");
    person.ChangeLastName(1990, "Volkova-Sergeeva");
    cout << person.GetFullNameWithHistory(1990) << endl;
    
    person.ChangeFirstName(1966, "Pauline");
    cout << person.GetFullNameWithHistory(1966) << endl;
    
    person.ChangeLastName(1960, "Sergeeva");
    for (int year : {1960, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }
    
    person.ChangeLastName(1961, "Ivanova");
    cout << person.GetFullNameWithHistory(1967) << endl;
    
    return 0;
}