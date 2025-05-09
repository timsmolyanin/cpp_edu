#include <iostream>
#include <string>
#include <vector>

using namespace std;

void MoveStrings(vector<string>& v1, vector<string>& v2);
void printVector(vector<string> vec);


int main(){
    vector<string> source = {"a", "b", "c"};
    vector<string> destination = {"z"};
    MoveStrings(source, destination);
    cout << "source: " << endl;
    printVector(source);
    cout << "destination: " << endl;
    printVector(destination);
    return 0;
}

void MoveStrings(vector<string>& v1, vector<string>& v2){
    for(auto s: v1){
        v2.push_back(s);
    }
    v1.clear();
}

void printVector(vector<string> vec){
    for(auto s : vec){
        cout << s;
    }
    cout << endl;
}
/*

Пример

vector<string> source = {"a", "b", "c"};
vector<string> destination = {"z"};
MoveStrings(source, destination);
// source должен оказаться пустым
// destination должен содержать строки "z", "a", "b", "c" именно в таком порядке
*/