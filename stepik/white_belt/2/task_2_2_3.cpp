#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Reverse(vector<int>& v);
void printVector(vector<int> vec);


int main(){
    vector<int> numbers = {1, 5, 3, 4, 2};
    Reverse(numbers);
    printVector(numbers);
    return 0;
}

void Reverse(vector<int>& v){
    int i = 0;
    int j = v.size() - 1;
    while(i < j){
        int tmp = v[i];
        v[i] = v[j];
        v[j] = tmp;
        i++;
        j--;
    }
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