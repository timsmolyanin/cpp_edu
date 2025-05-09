#include <iostream>
using namespace std;

int main() {
    double N, A, B, X, Y;
    cin >> N >> A >> B >> X >> Y;
    
    double finalPrice = N;
    if (N > B) {
        finalPrice = N * (1 - Y / 100.0);
    } else if (N > A) {
        finalPrice = N * (1 - X / 100.0);
    }
    
    cout << finalPrice << endl;
    return 0;
}