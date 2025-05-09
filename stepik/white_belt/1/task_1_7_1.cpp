

#include <iostream>
#include <cmath>

using namespace std;

/*
 * a and b 0 - 1 000 000
 * if b == 0 => Impossible

*/

int main(){
    int a, b;
    cin >> a >> b;
    if (b != 0){
        cout << a / b << endl;
    }
    else{
        cout << "Impossible" << endl;
    }

    return 0;
}