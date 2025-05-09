
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;


int main(){
    double number;
    string path = "input.txt";
    // string path = "numbers.txt";
    ifstream input_file(path);
    if (input_file.is_open()){
        while(input_file){
            input_file >> number;
            input_file.ignore(1);
            cout << fixed << setprecision(3) << number << endl; 
        }
    }
    return 0;
}