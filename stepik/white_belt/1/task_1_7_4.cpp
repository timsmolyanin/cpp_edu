

#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    cin >> s;
    char ref_s = 'f';
    int f_cnt = 0;
    int r_idx = 0;

    for (int i = 0; i <= s.length(); ++i){
        if(s[i] == ref_s){
            f_cnt++;
            r_idx = i;
        }
        if(f_cnt == 2) break;
    }
    if(f_cnt == 0){
        cout << -2 << endl;
    }
    else if(f_cnt == 1){
        cout << -1 << endl;
    }
    else if(f_cnt > 1){
        cout << r_idx << endl;
    }
    return 0;
}