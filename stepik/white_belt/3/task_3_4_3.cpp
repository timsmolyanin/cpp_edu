#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream> 
#include <map>
#include <functional>

using namespace std;

class Person {
  public:
    void ChangeFirstName(int year, const string& first_name) {
      // добавить факт изменения имени на first_name в год year
      dfn[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
      // добавить факт изменения фамилии на last_name в год year
      dln[year] = last_name;
    }
    string GetFullName(int year) {
      // получить имя и фамилию по состоянию на конец года year
      string fn = GetFirstName(year);
      string ln = GetLastName(year);
      string full_name = "Incognito";
      
      if (fn != "Unknown" && ln != "Unknown"){
        full_name = fn + " " + ln;
      }
      else if (fn == "Unknown" && ln != "Unknown" ){
        full_name = ln +  " with unknown first name";
      }
      else if (ln == "Unknown" && fn != "Unknown"){
        full_name = fn +  " with unknown last name";
      }
      return full_name;
    }

    string GetFullNameWithHistory(int year) {
      // получить все имена и фамилии по состоянию на конец года year
      string fn = GetFirstName(year);
      string ln = GetLastName(year);
      string full_name = "Incognito"; 
      string fn_hist = GetFirstNameHistory(year, fn);
      string ln_hist = GetLastNameHistory(year, ln);

      if (fn != "Unknown" && ln != "Unknown"){
        full_name = fn + " (" + fn_hist + ") " + ln + " (" + ln_hist + ")";
      }
      else if (fn == "Unknown" && ln != "Unknown" ){
        full_name = ln +  " with unknown first name";
      }
      else if (ln == "Unknown" && fn != "Unknown"){
        full_name = fn +  " with unknown last name";
      }
      return full_name;
    }
    
  private:
    // приватные поля
    map<int, string, greater<int>> dfn, dln;

    string GetFirstName(const int& year){
      if (dfn.size() != 0){
        if (dfn.count(year) == 1){
          return dfn[year];
        }
        else{
          for (auto& items : dfn){
            if (items.first < year){
              return dfn[items.first];
            }
          }
        }
      }
      return "Unknown";
    }

    string GetLastName(const int& year){
      if (dln.size() != 0){
        if (dln.count(year) == 1){
          return dln[year];
        }
        else{
          for (auto& items : dln){
            if (items.first < year){
              return dln[items.first];
            }
          }
        }
      }
      return "Unknown";
    }
  
  string GetFirstNameHistory(const int& year, const string& fn){
    vector<string> fnh = {};
    string fn_hist = "";
    if (dfn.size() != 0){
      for (auto& items : dfn){
        if(items.first < year){
          fnh.push_back(items.second);
        }
      }
    }
    reverse(fnh.begin(),fnh.end());
    fnh.erase(remove(fnh.begin(), fnh.end(), fn), fnh.end());
    for (auto& s : fnh){
      fn_hist += s;
      fn_hist += " ";
    }
    return fn_hist;
  }

  string GetLastNameHistory(const int& year, const string& ln){
    vector<string> lnh = {};
    string ln_hist = "";
    if (dln.size() != 0){
      for (auto& items : dln){
        if (items.first < year){
          lnh.push_back(items.second);
        }
      }
    }
    reverse(lnh.begin(),lnh.end());
    lnh.erase(remove(lnh.begin(), lnh.end(), ln), lnh.end());
    for (auto& s : lnh){
      ln_hist += s;
      ln_hist += " ";
    }
    return ln_hist;
  }
};
  
int main() {
  Person person;
  
  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1990, "Polina");
  person.ChangeLastName(1990, "Volkova-Sergeeva");
  cout << person.GetFullNameWithHistory(1990) << endl;
  
  person.ChangeFirstName(1966, "Pauline");
  cout << person.GetFullNameWithHistory(1966) << endl;
  
  person.ChangeLastName(1960, "Sergeeva");
  for (int year : {1960, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeLastName(1961, "Ivanova");
  cout << person.GetFullNameWithHistory(1967) << endl;
  
  return 0;
}