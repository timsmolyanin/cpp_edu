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
};
  
int main() {
  Person person;
  
  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullName(year) << endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }

  // person.ChangeLastName(3, "3_2nd");
  // person.ChangeLastName(6, "6_2nd");

  // for (int year : {3, 4, 5, 6}) {
  //     cout << person.GetFullName(year) << endl;
  // }

  // person.ChangeFirstName(-1, "-1_1st");
  // person.ChangeFirstName(2, "2_1st");

  // for (int year : {-1, 0, 1, 2, 3, 6}) {
  //     cout << person.GetFullName(year) << endl;
  // }

  // person.ChangeFirstName(-2, "-2_1st");
  // person.ChangeLastName(7, "7_2nd");

  // for (int year : {-3, -2, -1, 0, 1, 2, 3, 6, 7, 8}) {
  //     cout << person.GetFullName(year) << endl;
  // }

  // int year = 0;
  // std::cout << "year: " << year << '\n';
  // std::cout << person.GetFullName(year) << '\n';

  // year = 5;
  // person.ChangeFirstName(year, std::to_string(year) + "_first");
  // std::cout << "year: " << year << '\n';
  // std::cout << person.GetFullName(year) << '\n';

  // year = 3;
  // person.ChangeLastName(year, std::to_string(year) + "_last");
  // std::cout << "year: " << year << '\n';
  // std::cout << person.GetFullName(year) << '\n';

  // year = 2;
  // std::cout << "year: " << year << '\n';
  // std::cout << person.GetFullName(year) << '\n';

  // year = 0;
  // person.ChangeFirstName(year, std::to_string(year) + "_first");
  // person.ChangeLastName(year, std::to_string(year) + "_last");
  // std::cout << "year: " << year << '\n';
  // std::cout << person.GetFullName(year) << '\n';

  // year = 2;
  // std::cout << "year: " << year << '\n';
  // std::cout << person.GetFullName(year) << '\n';

  // year = 4;
  // std::cout << "year: " << year << '\n';
  // std::cout << person.GetFullName(year) << '\n';

  // year = 6;
  // std::cout << "year: " << year << '\n';
  // std::cout << person.GetFullName(year) << '\n';

  return 0;
}