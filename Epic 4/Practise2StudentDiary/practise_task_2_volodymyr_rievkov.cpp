#include<iostream>
#include<ctime>
using namespace std;

const int students_amount = 30;
const int grades_count = 20;;
int counter = 0;

struct Grades
{
    int math_register[grades_count];
    int english_register[grades_count];
    int history_register[grades_count];
};

struct Student
{
    string name;
    string surname;
    int age;
    string study_email;
    int number;
    Grades grades;
};

Student students[students_amount];

string set_name_value(string &name)
{
    cout << "Enter name: ";
    cin >> name;
    return name;
}

string set_surname_value(string &surname)
{
    cout << "Enter surname: ";
    cin >> surname;
    return surname;
}

int set_age_value(int &age)
{
    cout << "Enter age: ";
    cin >> age;
    return age;
}

string convert_uppercase_to_lowercase(string str)
{
    str[0] = tolower(str[0]);
    return str;
}

string generate_study_email(Student &student)
{
    return convert_uppercase_to_lowercase(student.name) + "." + convert_uppercase_to_lowercase(student.surname) + "@gmail.com";;
}

void print_student(Student &student)
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

Student* find_student(string &name, string &surname)
{
    for(int i = 0; i < students_amount; i++)
    {
        if(name == students[i].name && surname == students[i].surname)
        {
            return &students[i];
        }
    }
    return nullptr;
}

bool student_exists(string &name, string &surname)
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
    string name;
    string surname;
    int age;
    do
    {
        cout << "Press [1] for manual filling or [2] for auto filling: ";
        cin >> action;
    } while (action != 1 && action != 2);
    if(action == 1)
    {
        set_name_value(name);
        set_surname_value(surname);
        set_age_value(age);
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
            name = names[rand() % 30];
            surname = surnames[rand() % 30];
        } while (student_exists(name, surname));
        age = rand() % 13 + 7;
    }
    students[counter].name = name;
    students[counter].surname = surname;
    students[counter].age = age;
    students[counter].study_email = generate_study_email(students[counter]);
    students[counter].number = counter + 1;
    counter++;  
    cout << endl;
}

void delete_student()
{
    string name;
    string surname;
    int index;
    do
    {
        set_name_value(name);
        set_surname_value(surname);
    } while (!student_exists(name, surname));
    Student* student = find_student(name, surname);
    index = student->number - 1;
    for(index; index < students_amount - 1; index++)
    {
        students[index] = students[index + 1];
        if(students[index].number != index + 1)
        {
            students[index].number--;
        }
    }
    counter--;
}

void print_register(int *student_register)
{
    for(int i = 0; i < grades_count; i++)
    {
        if(student_register[i] > 12 || student_register[i] < 1)
        {
            break;
        }
        cout << "|" << student_register[i] << "| ";
    }
    cout << endl;
}

void print_student_grades(Student &student)
{
    cout << student.name << " " << student.surname << endl;
    cout << "---Math ";
    print_register(student.grades.math_register);
    cout << "---English ";
    print_register(student.grades.english_register);
    cout << "---History ";
    print_register(student.grades.history_register);
    cout << "---Average grade ";
}

void print_all_students_grades()
{
    for(int i = 0; i < students_amount; i++)
    {
        if(students[i].name == "")
        {
            break;
        }
        print_student_grades(students[i]);
    }
}

int main()
{
    srand(time(nullptr));
    add_student();
    add_student();
    add_student();
    print_all_students();
    print_all_students_grades();
}