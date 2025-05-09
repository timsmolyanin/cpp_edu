
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <map>
#include <set>
#include <vector>

using namespace std;

void EnsureEqual(const string& left, const string& right){
    if (left != right){
        string e = left + " != " + right;
        throw runtime_error(e);
    }
}

// int main() {
//     try {
//         EnsureEqual("C++ White", "C++ White");
//         EnsureEqual("C++ White", "C++ Yellow");
//     }
//     catch (runtime_error& e) {
//         cout << e.what() << endl;
//     }
//     return 0;
// }