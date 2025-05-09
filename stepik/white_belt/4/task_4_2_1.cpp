
#include <fstream>
#include <iostream>

using namespace std;


int main(){
    string line;
    ifstream input_file("input.txt");
    if (input_file.is_open()){
        while (getline(input_file, line)){
            cout << line << endl;
        }
    }

    return 0;
}