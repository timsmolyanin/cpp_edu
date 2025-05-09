#include <iostream>
#include <cstdlib>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <stdexcept>
#include <iomanip>

using namespace std;

class Date {
public:
    Date() : year(0), month(0), day(0) {}
    
    Date(int y, int m, int d) {
        if (m < 1 || m > 12) {
            throw invalid_argument("Month value is invalid: " + to_string(m));
        }
        if (d < 1 || d > 31) {
            throw invalid_argument("Day value is invalid: " + to_string(d));
        }
        year = y;
        month = m;
        day = d;
    }
    
    int GetYear() const { return year; }
    int GetMonth() const { return month; }
    int GetDay() const { return day; }

private:
    int year;
    int month;
    int day;
};

ostream& operator<<(ostream& stream, const Date& date) {
    stream << setw(4) << setfill('0') << date.GetYear() << "-"
           << setw(2) << setfill('0') << date.GetMonth() << "-"
           << setw(2) << setfill('0') << date.GetDay();
    return stream;
}

istream& operator>>(istream& stream, Date& date) {
    int y, m, d;
    char dash1, dash2;
    string input;
    
    ios::pos_type start_pos = stream.tellg();
    
    if (!(stream >> y >> dash1 >> m >> dash2 >> d)) {
        stream.clear();
        stream.seekg(start_pos);
        getline(stream, input, ' ');
        throw invalid_argument("Wrong date format: " + input);
    }
    
    if (dash1 != '-' || dash2 != '-') {
        stream.clear();
        stream.seekg(start_pos);
        getline(stream, input, ' ');
        throw invalid_argument("Wrong date format: " + input);
    }
    
    try {
        date = Date(y, m, d);
    } catch (const invalid_argument&) {
        throw; 
    }
    
    return stream;
}

Date ParseDate(const string& date_str) {
    istringstream iss(date_str);
    Date d;
    iss >> d;
    if (iss.peek() != EOF) {
        throw invalid_argument("Wrong date format: " + date_str);
    }
    
    return d;
}

bool operator<(const Date& lhs, const Date& rhs) {
    return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} < 
           vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

class Database {
public:
    void AddEvent(const Date& date, const string& event) {
        data[date].insert(event);
    }

    bool DeleteEvent(const Date& date, const string& event) {
        if (data.count(date) && data.at(date).count(event)) {
            data.at(date).erase(event);
            if (data.at(date).empty()) {
                data.erase(date);
            }
            return true;
        }
        return false;
    }

    int DeleteDate(const Date& date) {
        if (!data.count(date)) return 0;
        int count = data.at(date).size();
        data.erase(date);
        return count;
    }

    vector<string> Find(const Date& date) const {
        if (!data.count(date)) return {};
        return vector<string>(data.at(date).begin(), data.at(date).end());
    }

    void Print() const {
        for (const auto& [date, events] : data) {
            for (const auto& event : events) {
                cout << date << " " << event << endl;
            }
        }
    }

private:
    map<Date, set<string>> data;
};

int main() {
    Database db;
    string command;

    while (getline(cin, command)) {
        if (command.empty()) continue;

        istringstream iss(command);
        string cmd;
        iss >> cmd;

        try {
            if (cmd == "Add") {
                string date_str, event;
                if (!(iss >> date_str >> event)) throw invalid_argument("Wrong command format");
                
                Date date = ParseDate(date_str);
                db.AddEvent(date, event);

            } else if (cmd == "Del") {
                string date_str, event;
                if (!(iss >> date_str)) throw invalid_argument("Wrong command format");
                
                Date date = ParseDate(date_str);
                
                if (iss >> event) {
                    if (db.DeleteEvent(date, event)) {
                        cout << "Deleted successfully" << endl;
                    } else {
                        cout << "Event not found" << endl;
                    }
                } else {
                    int count = db.DeleteDate(date);
                    cout << "Deleted " << count << " events" << endl;
                }

            } else if (cmd == "Find") {
                string date_str;
                if (!(iss >> date_str)) throw invalid_argument("Wrong command format");
                
                Date date = ParseDate(date_str);
                vector<string> events = db.Find(date);
                for (const auto& e : events) {
                    cout << e << endl;
                }

            } else if (cmd == "Print") {
                db.Print();

            } else {
                throw invalid_argument("Unknown command: " + cmd);
            }

        } catch (const exception& e) {
            cout << e.what() << endl;
            return 0;
        }
    }

    return 0;
}