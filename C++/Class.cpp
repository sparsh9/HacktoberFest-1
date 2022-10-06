#include <iostream>
#include <vector>
using namespace std;

class Name
{
public:
    string first_name;
    string last_name;

    Name(pair<string, string> my_name)
    {
        first_name = my_name.first;
        last_name = my_name.second;
    }
};

class Address
{
public:
    string house_no;
    string area;
    string state;
    string pincode;

    Address(vector<string> data)
    {
        house_no = data[0];
        area = data[1];
        state = data[2];
        pincode = data[3];
    }
};

class Student
{
public:
    Name *name;
    int age;
    Address *address;
    bool is_sick;
    vector<Student *> friends;

    Student(pair<string, string> n, int a, bool is_s, vector<string> add)
    {
        name = new Name(n);
        age = a;
        is_sick = is_s;
        address = new Address(add);
    }

    void makeFriend(Student* frnd1, Student* frnd2){
        frnd1->friends.push_back(frnd2);
        frnd2->friends.push_back(frnd1);
    }

    static void print(Student *s)
    {
        cout << "Name: " << s->name->first_name << " " << s->name->last_name << endl;
        cout << "Age: " << s->age << endl;
        cout << "Is sick: " << s->is_sick << endl;
        cout << "Address: ";
        cout << s->address->house_no << ", " << s->address->area << ", " << s->address->state << ", " << s->address->pincode << endl;
        cout << "Friends: ";
        for (auto frnd : s->friends)
        {
            cout << frnd->name->first_name << ", ";
        }
        cout << "\n\n";
    }
};

int main()
{
    Student *s1 = new Student({"Anuj", "Sharma"}, 22, true, {"40", "Mansarover", "up", "244001"});
    Student *s2 = new Student({"Shrivis", ""}, 22, false, {"38", "Saket", "Delhi", "110030"});
    Student *s3 = new Student({"Suraj", "Agarwal"}, 22, false, {"101", "Simdega", "Jharkhand", "835223"});

    // s1->friends.push_back(s2);
    // s1->friends.push_back(s3);
    // s3->friends.push_back(s1);
    // s2->friends.push_back(s1);
    s1->makeFriend(s1,s2);
    s1->makeFriend(s1,s3);

    s1->print(s1);
    s2->print(s2);
    s3->print(s3);

    return 0;
}
