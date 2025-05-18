
#include <iostream>
#include <map>

using namespace std;



int main() {
    map<int, int> m = {
        {2, 3},
        {4, 5},
        {6, 7}
    };
    cout << m[2] << endl;
    // for (int i = 0; i < static_cast<int>(m.size()); ++i){
    //     cout << m[i] << endl;
    // }

    return 0;
}