#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool IsPalindrom(string str);
vector<string> PalindromFilter(vector<string> istr, int l);
void printVector(vector<string> vec);


int main(){
    vector<string> s1 = {"abacaba", "aba"};
    vector<string> s2 = {"weew", "bro", "code"};
    printVector(PalindromFilter(s1, 5));
    printVector(PalindromFilter(s1, 2));
    printVector(PalindromFilter(s2, 4));
    return 0;
}

bool IsPalindrom(string str){
    int i = 0;
    int j = str.size() - 1;

    while(i < j){
        if(str[i] != str[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

vector<string> PalindromFilter(vector<string> words, int minLength){
    vector<string> pwords = {};
    for(string w : words){
        if(w.length() >= minLength && IsPalindrom(w)){
            pwords.push_back(w);
        }
    }
    return pwords;
}

void printVector(vector<string> vec){
    for(auto s : vec){
        cout << s;
    }
    cout << endl;
}