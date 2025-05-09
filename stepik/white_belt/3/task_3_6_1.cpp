#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class ReversibleString{
  public:
  ReversibleString(){
    some_string = "";
  }

  ReversibleString(const string& s){
    some_string = s;
  }

  void Reverse(){
    string tmp_str = "";
    for (int i = some_string.size()-1; i >= 0; --i){
      tmp_str += some_string[i];
    }
    some_string = tmp_str;
  }

  string ToString() const{
    return some_string;
  }
  private:
  string some_string;
};


int main() {
  ReversibleString s("live");
  s.Reverse();
  cout << s.ToString() << endl;
  
  s.Reverse();
  const ReversibleString& s_ref = s;
  string tmp = s_ref.ToString();
  cout << tmp << endl;
  
  ReversibleString empty;
  cout << '"' << empty.ToString() << '"' << endl;
  return 0;
}