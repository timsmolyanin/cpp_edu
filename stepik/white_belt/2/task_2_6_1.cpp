#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;


int main(){
    int number;
    cin >> number;
    vector<string> strings(number);
    for(int i = 0; i < number; ++i){
        cin >> strings[i];
    }
    set<string> uniq_str(begin(strings), end(strings));
    cout << uniq_str.size() << endl;

    return 0;
}
