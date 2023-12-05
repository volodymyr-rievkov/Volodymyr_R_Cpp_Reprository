#include<iostream>
#include<ctime>
using namespace std;

const int students_amount = 30;
int counter = 0;

struct Student
{
    string name;
    string surname;
    int age;
    string study_email;
    int number;
};

Student students[students_amount];

string get_name()
{
    string name;
    cout << "Enter name: ";
    cin >> name;
    return name;
}

string get_surname()
{
    string surname;
    cout << "Enter surname: ";
    cin >> surname;
    return surname;
}

int get_age()
{
    int age;
    cout << "Enter age: ";
    cin >> age;
    return age;
}

string convert_uppercase_to_lovercase(string str)
{
    for(int i = 0; i < str.length(); i++)
    {
        str[i] = tolower(str[i]);
    }
    return str;
}

string generate_study_email(Student student)
{
    return convert_uppercase_to_lovercase(student.name) + "." + convert_uppercase_to_lovercase(student.surname) + "@gmail.com";;
}

void print_student(Student student)
{
    cout << "-----Student №" << student.number << "-----" << endl;
    cout << "Name: " << student.name << endl;
    cout << "Surame: " << student.surname << endl;
    cout << "Age: " << student.age << endl;
    cout << "Study email: " << student.study_email << endl;
    cout << endl;
}

void print_all_students()
{
    for(int i = 0; i < students_amount; i++)
    {
        if(students[i].name.length() == 0)
        {
            break;
        }
        print_student(students[i]);
    }
}

bool is_existed(string name, string surname)
{
    for(int i = 0; i < students_amount; i++)
    {
        if(name == students[i].name && surname == students[i].surname)
        {
            return true;
        }
    }
    return false;
}

void add_student()
{
    int action;
    do
    {
        cout << "Press [1] for manual filling or [2] for auto filling: ";
        cin >> action;
    } while (action != 1 && action != 2);
    if(action == 1)
    {
        students[counter].name = get_name();
        students[counter].surname = get_surname();
        students[counter].age = get_age();
        students[counter].study_email = generate_study_email(students[counter]);
        students[counter].number = counter + 1;
    }
    else
    {
        string names[students_amount] = {
        "Aiden", "Brooklyn", "Carter", "Delilah", "Elijah",
        "Faith", "Grayson", "Harper", "Isaiah", "Jasmine",
        "Kaden", "Layla", "Mason", "Nevaeh", "Owen",
        "Peyton", "Quinn", "Riley", "Sophia", "Tyler",
        "Upton", "Vanessa", "Wyatt", "Ximena", "Yasmine",
        "Zane", "Ava", "Brayden", "Chloe", "Daniel"};
        string surnames[students_amount] = {
        "Anderson", "Baker", "Clark", "Davis", "Edwards",
        "Fisher", "Garcia", "Hill", "Irwin", "Johnson",
        "Keller", "Lopez", "Martinez", "Nelson", "Owens",
        "Perez", "Quinn", "Rodriguez", "Smith", "Taylor",
        "Upton", "Valdez", "Watson", "Xavier", "Young",
        "Zimmerman", "Adams", "Brown", "Chavez", "Dixon"};
        do
        {
            students[counter].name = names[rand() % 30];
            students[counter].surname = surnames[rand() % 30];
        } while (is_existed(students[counter].name, students[counter].surname));
        students[counter].age = rand() % 13 + 7;
        students[counter].study_email = generate_study_email(students[counter]);
        students[counter].number = counter + 1;
    }
    counter++;  
    cout << endl;
}

void delete_student()
{
    string name;
    string surname;
    do
    {
        name = get_name();
        surname = get_surname();
    } while (!is_existed(name, surname));

    
}

int main()
{
    srand(time(nullptr));
    add_student();
    add_student();
    add_student();
    print_all_students();
}