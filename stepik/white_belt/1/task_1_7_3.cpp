
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int a, b;
    vector<int> res;
    cin >> a >> b;
    bool begining = true;
    for (int i = a; i <= b; ++i){
        if(i % 2 == 0){
            res.push_back(i);
        }
    }
    for(auto i : res){
        if(!begining){
            cout << " ";
        }
        begining = false;
        cout << i;
    }
    cout << endl;

    return 0;
}