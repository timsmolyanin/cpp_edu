
#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

void Print(vector<int>& nums){
    bool tmp = true;
    for (auto& n : nums){
        if (!tmp){
            cout << ' ';
        }
        tmp = false;
        // cout << n;
        cout << setw(10) << n;
    }
    cout << endl;
    nums.clear();
}

int main(){
    int row_cnt, column_cnt;
    vector<int> row;
    string path = "input.txt";
    // string path = "numbers.txt";
    ifstream input_file(path);
    if (input_file.is_open()){
        input_file >> row_cnt;
        input_file >> column_cnt;
        for (int i = 0; i < row_cnt; ++i){
            for (int j = 0; j < column_cnt; ++j){
                int n = 0;
                input_file >> n;
                input_file.ignore(1);
                row.push_back(n); 
            }
            Print(row);
        }

    }
    return 0;
}