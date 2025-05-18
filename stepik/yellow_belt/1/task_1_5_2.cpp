
#include <string>
#include <iostream>
#include <map>
#include <exception>

using namespace std;

template <class Key, class Value>
Value& GetRefStrict(map<Key, Value>& m, const Key& key);

template <class Key, class Value>
Value& GetRefStrict(map<Key, Value>& m, const Key& key){
    if (m.count(key) < 1){
        throw runtime_error("");
    }
    else{
        return m[key];
    }
}

int main(){
    map<int, string> m = {{0, "value"}};
    string& item = GetRefStrict(m, 1);
    item = "newvalue";
    cout << m[0] << endl; // выведет newvalue

    return 0;
}