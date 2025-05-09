#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Incognizable{
  public:
  Incognizable(){
    param1 = 0;
    param2 = 0;
  }
  Incognizable(const int& p1){
    param1 = p1;
    param2 = 0;
  }
  Incognizable(const int& p1, const int& p2){
    param1 = p1;
    param2 = p2;
  }
  private:
  int param1, param2;
};

int main() {
  Incognizable a;
  Incognizable b = {};
  Incognizable c = {0};
  Incognizable d = {0, 1};
  return 0;
}