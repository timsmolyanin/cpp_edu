#include <iostream>
#include <string>
#include <map>
#include <set>
#include <sstream> 

using namespace std;


void AddWordsToDict(map<string, set<string>>& dict, const string& word1, const string& word2){
    dict[word1].insert(word2);
    dict[word2].insert(word1);
}


int main(){
    map<string, set<string>> dict;
    int cmd_cnt;
    string input_line;
    string cmd;

    cin >> cmd_cnt;
    cin.ignore();
    for(int i = 0; i < cmd_cnt; ++i){
        getline(cin, input_line);
        istringstream iss(input_line);
        iss >> cmd;
        if (cmd == "ADD"){
            string word1, word2;
            iss >> word1 >> word2;
            AddWordsToDict(dict, word1, word2);
        }
        else if (cmd == "COUNT"){
            string word;
            iss >> word;
            cout << dict[word].size() << endl;
        }
        else if (cmd == "CHECK"){
            string word1, word2;
            iss >> word1 >> word2;
            if (dict.count(word1) != 0 || dict.count(word2) != 0){
                if (dict[word1].count(word2) != 0){
                    cout << "YES" << endl;
                }
                else if (dict[word2].count(word1) != 0){
                    cout << "YES" << endl;
                }
                else{
                    cout << "NO" << endl;    
                }
            }
            else {
                cout << "NO" << endl;
            }
        }

    }

    return 0;
}


