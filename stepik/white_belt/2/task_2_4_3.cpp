#include <iostream>
#include <string>
#include <vector>
#include <sstream> 

using namespace std;

void AddTaskToList(vector<vector<string>>& todo_list, const int day, const string task);
void PrintTasksOfDay(const vector<vector<string>>& todo_list, const int day);
void MoveTasksToNextMonth(vector<vector<string>>& todo_list);
void PrintVector(const vector<string>& vec);

int current_month = 0;
vector<int> MONTHS = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(){
    
    vector<vector<string>> todo_list(MONTHS[current_month]);

    int cmd_cnt;
    string input_line;
    string cmd;
    int arg;

    cin >> cmd_cnt;
    cin.ignore();
    for(int i = 0; i < cmd_cnt; ++i){
        getline(cin, input_line);
        istringstream iss(input_line);
        iss >> cmd;
        if(cmd == "NEXT"){
            MoveTasksToNextMonth(todo_list);
        }
        else{
            iss >> arg;
            if(cmd == "ADD"){
                string s;
                iss >> s;
                AddTaskToList(todo_list, (int)arg, s);
            }
            else if(cmd == "DUMP"){
                PrintTasksOfDay(todo_list, (int)arg);
            }
        }

    }
    return 0;
}

void AddTaskToList(vector<vector<string>>& todo_list, const int day, const string task){
    if(day <= MONTHS[current_month])
        todo_list[day-1].push_back(task);
}

void PrintTasksOfDay(const vector<vector<string>>& todo_list, const int day){
    if(day <= MONTHS[current_month]){
        bool tmp = true;

        int cnt_of_tasks = todo_list[day-1].size();
        vector<string> tasks = todo_list[day-1];
        cout << cnt_of_tasks << " ";
        
        for(auto task : tasks){
            if(!tmp){
                cout << " ";
            }
            tmp = false;
            cout << task;
        }
        cout << endl;
    }
}

void MoveTasksToNextMonth(vector<vector<string>>& todo_list){
    /*
     * if NEXT MONTH day cnt > CURRENT => additional days are empty
     * if NEXT MONTH day cnt < CURRENT => all tasks to last day NEXT MONTH
     * count of NEXT cmds can be > 11 => so need start from 0 if >
    */

    current_month += 1;
    if(current_month > 11){
        current_month = 0;
    }
    int cur_month_day_cnt = MONTHS[current_month];
    // cout << "CUR MONTH = " << current_month << " " << "DAYS = " << cur_month_day_cnt << endl;
    // cout << cur_month_day_cnt << " " << MONTHS[current_month-1] << endl;
    if(cur_month_day_cnt > MONTHS[current_month-1]){
        // cout << "CUR > PREV" << endl;
        todo_list.resize(cur_month_day_cnt);
    }
    else if(cur_month_day_cnt < MONTHS[current_month-1]){
        vector<string> tmp = {};
        // cout << "CUR < PREV" << endl;
        int additional_days = MONTHS[current_month-1] - cur_month_day_cnt; // 31 - 28 = 3
        for(int i = cur_month_day_cnt; i <= MONTHS[current_month-1]-1; ++i){ // from 27 to 30
            tmp.insert(end(tmp), begin(todo_list[i]), end(todo_list[i]));
        }
        todo_list.resize(cur_month_day_cnt);
        todo_list.back().insert(end(todo_list.back()), begin(tmp), end(tmp));
    }
}

void PrintVector(const vector<string>& vec){
    for(auto i : vec){
        bool tmp = true;
            if(!tmp){
                cout << " ";
            }
            tmp = false;
            cout << i;
        }
        cout << endl;
}
