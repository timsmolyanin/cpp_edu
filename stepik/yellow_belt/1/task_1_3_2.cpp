
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

int main(){
    int blocks_cnt;
    int density;
    int w, h, d;
    uint64_t result = 0;
    cin >> blocks_cnt >> density;

    for(int i = 0; i < blocks_cnt; ++i){
        cin >> w >> h >> d;
        uint64_t volume = w * h * d;
        result += volume * density; 
    }
    cout << result << endl;

    return 0;
    
}