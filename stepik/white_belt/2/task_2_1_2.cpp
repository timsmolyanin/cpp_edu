#include <iostream>
#include <string>

using namespace std;

bool IsPalindrom(string str);

int main(){
    string s1 = "madam";
    string s2 = "gentleman";
    string s3 = "x";
    cout << s1 << " is " << IsPalindrom(s1) << endl;
    cout << s2 << " is " << IsPalindrom(s2) << endl;
    cout << s3 << " is " << IsPalindrom(s3) << endl;
    return 0;
}

bool IsPalindrom(string str){
    int i = 0;
    int j = str.size() - 1;

    while(i < j){
        if(str[i] != str[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}