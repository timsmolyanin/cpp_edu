#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  // код
  int cnt = count_if(begin(v), end(v), [](int x){return x % 2 != 0;});
  cout << cnt << endl;
}