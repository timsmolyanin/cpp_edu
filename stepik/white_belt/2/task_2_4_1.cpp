#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main(){
    int number;
    int day_count = 0;
    vector<int> res;
    cin >> number;
    vector<int> measurments(number);
    for(int i = 0; i < number; ++i){
        cin >> measurments[i];
    }
    int sum = 0;
    for(auto n : measurments){
        sum += n; 
    }
    int average = sum / number;
    for(int i = 0; i < measurments.size(); ++i){
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


void printVector(vector<int> vec){
    for(auto s : vec){
        cout << s;
    }
    cout << endl;
}