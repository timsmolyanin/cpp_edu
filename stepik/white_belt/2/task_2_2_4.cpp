#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> Reversed(const vector<int>& v);
void printVector(vector<int> vec);


int main(){
    vector<int> numbers = {1, 5, 3, 4, 2};
    vector<int> r = Reversed(numbers);
    printVector(r);
    return 0;
}

vector<int> Reversed(const vector<int>& v){
    vector<int> r = {};
    int j = v.size() - 1;
    while(j >= 0){
        r.push_back(v[j]);
        j--;
    }
    return r;
}

void printVector(vector<int> vec){
    for(auto s : vec){
        cout << s;
    }
    cout << endl;
}
/*
vector<int> numbers = {1, 5, 3, 4, 2};
Reverse(numbers);
// numbers должен оказаться равен {2, 4, 3, 5, 1}
*/