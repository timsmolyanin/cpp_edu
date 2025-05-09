

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

map<char, int> BuildCharCounters(const string& words);

int main(){
    int count_of_words;
    vector<vector<string>> words;
    vector<string> answers;

    cin >> count_of_words;
    for(int i = 0; i < count_of_words; ++i){
        string tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        words.push_back({tmp1, tmp2});
    }

    for(auto pair_words : words){
        map<char, int> m1, m2;
        m1 = BuildCharCounters(pair_words[0]);
        m2 = BuildCharCounters(pair_words[1]);
        if (m1 == m2){
            answers.push_back("YES");
        }
        else{
            answers.push_back("NO");
        }
    }

    for (auto i : answers){
        cout << i << endl;
    }

    return 0;
}


map<char, int> BuildCharCounters(const string& words){
    map<char, int> counters;
    for (auto word : words){
        ++counters[word];
    }
    return counters;
}