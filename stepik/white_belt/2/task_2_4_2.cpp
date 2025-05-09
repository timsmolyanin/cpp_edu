#include <iostream>
#include <string>
#include <vector>
#include <sstream> 

using namespace std;

/*
 * 0 - quiet person
 * 1 - worry person
 * 
*/

void RemovePersonFromQueue(vector<int>& queue, const int count_off_person);
void AddQuietPersonToQueue(vector<int>& queue, const int count_off_person);
void MakePersonQuiet(vector<int>& queue, const int index_in_queue);
void MakePersonWorry(vector<int>& queue, const int index_in_queue);
void PrintWorryCount(const vector<int>& queue);
void PrintQueue(const vector<int>& queue);

int main(){
    vector<int> pqueue = {};
    int cmd_cnt;
    string input_line;
    string cmd;
    int arg;

    cin >> cmd_cnt;
    cin.ignore();
    for(int i = 0; i < cmd_cnt; ++i){
        getline(cin, input_line);
        istringstream iss(input_line);
        int arg = 0;
        iss >> cmd;
        if(cmd == "WORRY_COUNT"){
            PrintWorryCount(pqueue);
        }
        else{
            iss >> arg;
            if(cmd == "WORRY"){
                iss >> arg;
                MakePersonWorry(pqueue, (int)arg);
            }
            else if(cmd == "QUIET"){
                iss >> arg;
                MakePersonQuiet(pqueue, (int)arg);
            }
            else if(cmd == "COME"){
                iss >> arg;
                if(arg > 0){
                    AddQuietPersonToQueue(pqueue, (int)arg);
                }
                else{
                    int pos_arg = -1 * (int)arg;
                    RemovePersonFromQueue(pqueue, pos_arg);
                }
            }

        }
         
    }
    return 0;
}

void AddQuietPersonToQueue(vector<int>& queue, const int count_off_person){
    for(int i = 0; i < count_off_person; ++i){
        queue.push_back(0);
    }
}

void RemovePersonFromQueue(vector<int>& queue, const int count_off_person){
    for(int i = 0; i < count_off_person; ++i){
        queue.pop_back();
    }
}

void MakePersonQuiet(vector<int>& queue, const int index_in_queue){
    queue[index_in_queue] = 0;
}

void MakePersonWorry(vector<int>& queue, const int index_in_queue){
    queue[index_in_queue] = 1;
}

void PrintWorryCount(const vector<int>& queue){
    int worry_cnt = 0;
    for(auto p : queue){
        if(p){
            worry_cnt++;
        }
    }
    cout << worry_cnt << endl;
}

void PrintQueue(const vector<int>& queue){
    for(auto i : queue){
        cout << i << " ";
    }
    cout << endl;
}