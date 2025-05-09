
#include <string>
#include <iostream>

using namespace std;


struct Specialization{
    string value;
    explicit Specialization(const string& spec){
        value = spec;
    }
};

struct Course{
    string value;
    explicit Course(const string& course){
        value = course;
    }
};

struct Week{
    string value;
    explicit Week(const string& week){
        value = week;
    }
};


struct LectureTitle {
    string specialization;
    string course;
    string week;

    LectureTitle(Specialization spec, Course cour, Week wk){
        specialization = spec.value;
        course = cour.value;
        week = wk.value;
    }
};

int main(){
    LectureTitle title(
        Specialization("C++"),
        Course("White belt"),
        Week("4th")
    );

    
    cout << title.specialization << " " << title.course << " " << title.week << endl;
    return 0;
}