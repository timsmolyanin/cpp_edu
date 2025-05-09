

#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double a, b, c;
    cin >> a >> b >> c;

    if (a == 0 && b != 0 && c != 0){
        double x = -(c / b);
        cout << x << endl;
    }
    else if (a != 0 && b == 0 && c == 0){
        cout << 0 << endl;
    }
    else if (a != 0 && b == 0 && c != 0){
        double v = -(c / a);
        if (v > 0){
            double x1 = sqrt(v);
            double x2 = -sqrt(v);
            cout << x1 << " " << x2 << endl;
        }
        else return 0;
    }
    else if(a != 0 && b != 0 && c == 0){
        double x1 = 0;
        double x2 = -(b / a);
        cout << x1 << " " << x2 << endl;
    }
    else if(a != 0 && b != 0 && c != 0){

        // descrimenant
        double d = (b * b) - (4 * (a * c));
        if (d < 0){
            // no roots
            return 0;
        }
        else if (d == 0){
            double x = -(b / (2 * a));
            cout << x << endl;
        }
        else if(d > 0){
            double x1 = -(b - sqrt(d)) / (2 * a);
            double x2 = -(b + sqrt(d)) / (2 * a);
            cout << x1 << " " << x2 << endl;
        }
    }

    return 0;
}