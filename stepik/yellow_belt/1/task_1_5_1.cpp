#include <vector>
#include <iostream>
#include <utility>
#include <map>

using namespace std;

template <typename T>
T Sqr(T n);

template <class First, class Second>
pair<First, Second> operator* (const pair<First, Second>& p1, const pair<First, Second>& p2);

template <class Key, class Value>
map<Key, Value> operator* (const map<Key, Value>& m1, const map<Key, Value>& m2);

template <class Value>
vector<Value> operator* (const vector<Value>& v1, const vector<Value>& v2);


template <typename T>
T Sqr(T n){
    return n * n;
}

template <class First, class Second>
pair<First, Second> operator* (const pair<First, Second>& p1, const pair<First, Second>& p2){
    First first = p1.first * p2.first;
    Second second = p1.second * p2.second;
    return {first, second};
}

template <class Key, class Value>
map<Key, Value> operator* (const map<Key, Value>& m1, const map<Key, Value>& m2){
    map<Key, Value> r;
    for (auto& [key, val] : m1){
        r[key] = val * val;
    }
    return r;
}

template <class Value>
vector<Value> operator* (const vector<Value>& v1, const vector<Value>& v2){
    vector<Value> r;
    for (auto& val : v1){
        r.push_back(val * val);
    }
    return r;
}


int main(){
    vector<int> v = {1, 2, 3};
    cout << "vector:";
    for (int x : Sqr(v)) {
        cout << ' ' << x;
    }
    cout << endl;

    map<int, pair<int, int>> map_of_pairs = {
        {4, {2, 2}},
        {7, {4, 3}}
    };

    cout << "map of pairs:" << endl;
    for (const auto& x : Sqr(map_of_pairs)) {
        cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }


    map<int, vector<int>> map_of_vectors = {
        {4, {3, 4 , 5, 6}},
        {7, {7, 8, 9, 10}}
    };

    auto mm = Sqr(map_of_vectors);
    for (auto& [key, value] : mm){
        cout << key << ": ";
        for (auto& v : value){
            cout << v << " ";
        }
        cout << endl;
    }

    cout << endl;
}