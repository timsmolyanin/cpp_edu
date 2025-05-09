#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream> 

using namespace std;

class SortedStrings {
    public:
      void AddString(const string& s) {
        // добавить строку s в набор
        strings.push_back(s);
        sort(strings.begin(), strings.end());
      }
      vector<string> GetSortedStrings() {
        // получить набор из всех добавленных строк в отсортированном порядке
        return strings;
      }
    private:
      vector<string> strings;
};

void PrintSortedStrings(SortedStrings& strings) {
    for (const string& s : strings.GetSortedStrings()) {
      cout << s << " ";
    }
    cout << endl;
}
  
int main() {
SortedStrings strings;

strings.AddString("first");
strings.AddString("third");
strings.AddString("second");
PrintSortedStrings(strings);

strings.AddString("second");
PrintSortedStrings(strings);

return 0;
}