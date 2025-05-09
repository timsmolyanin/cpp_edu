#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream> 

using namespace std;

bool comp(string s1, string s2){
    string s1_tmp = s1;
    string s2_tmp = s2;
    s1 = "";
    s2 = "";
    for (auto& s : s1_tmp){
        s1 += tolower(s);
    }
    for (auto& s : s2_tmp){
        s2 += tolower(s);
    }
    return s1 < s2;
}

int main() {
    int char_cnt;
    string input_line;
    getline(cin, input_line);
    istringstream iss(input_line);
    iss >> char_cnt;

    vector<string> chars;
    string ch;

    for (int i = 0; i < char_cnt; ++i){
        iss >> ch;
        chars.push_back(ch);
    }

    sort(chars.begin(), chars.end(), comp);

    for (auto& n : chars){
        cout << n << " ";
    }
    cout << endl;
  
}