
#include <fstream>
#include <iostream>

using namespace std;


int main(){
    string line;
    const string path = "output.txt";
    string ftext = "";
    ifstream input_file("input.txt");
    if (input_file.is_open()){
        while (getline(input_file, line)){
            ftext += line + "\n";
        }
    }
    ofstream output(path);
    output << ftext;

    return 0;
}