

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> res;
    while(n > 0){
        if(n % 2 == 0){
            res.push_back(0);
        }
        else{
            res.push_back(1);
        }
        n /= 2;
    }
    reverse(res.begin(), res.end());
    for(int i : res){
        cout << i;
    }
    cout << endl;
    return 0;
}