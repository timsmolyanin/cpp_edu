

#include <iostream>


using namespace std;

int Factorial(int n);

int main(){
    int r = Factorial(1);
    cout << r << endl;
    int q = Factorial(-2);
    cout << q << endl;
    int w = Factorial(4);
    cout << w << endl;

    int e = Factorial(7);
    cout << e << endl;
    int y = Factorial(15);
    cout << y << endl;
    int t = Factorial(22);
    cout << t << endl;
    return 0;
}
int Factorial(int n){
    if(n <= 1){
        return 1;
    }
    int factorial = 1;
    for(int i = 1; i <= n; ++i){
        factorial *= i; 
    }
    return factorial;
}