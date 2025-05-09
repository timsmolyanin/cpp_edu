#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

void PrintVector(vector<int> vec){
    for(auto s : vec){
        cout << s;
    }
    cout << endl;
}

int main(){
    int number;
    int day_count = 0;
    vector<int> res;
    cin >> number;
    if (number <= 0){
        throw invalid_argument("");
    }
    vector<int> measurments(number);
    for(int i = 0; i < number; ++i){
        cin >> measurments[i];
    }
    int64_t sum = 0;
    for(auto n : measurments){
        sum += n; 
    }
    int average = sum / number;
    for(int i = 0; i < static_cast<int>(measurments.size()); ++i){
        if(measurments[i] > average){
            day_count++;
            res.push_back(i);
        }
    }
    cout << day_count << endl;
    for(auto i : res){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}