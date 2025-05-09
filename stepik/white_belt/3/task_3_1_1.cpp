#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream> 

using namespace std;

bool func(int x, int y){
    if (x < 0) x = x * -1;
    if (y < 0) y = y * -1;
    return x < y;
}

int main() {
    int num_cnt;
    string input_line;
    getline(cin, input_line);
    istringstream iss(input_line);
    iss >> num_cnt;

    vector<int> numbers;
    int number;

    for (int i = 0; i < num_cnt; ++i){
        iss >> number;
        numbers.push_back(number);
    }

    sort(numbers.begin(), numbers.end(), func);

    for (auto& n : numbers){
        cout << n << " ";
    }
    cout << endl;
  
}