#include<iostream>
using namespace std;
struct Student
{
    string name;
    string surname;
    int age;
    double height;
    double weight;
    struct
    {
        string city;
        string street;
    }Adress;
    
};
int main()
{
    Student Andriy;
    Andriy.name = "Andriy";
    Andriy.surname = "Vinnytskiy";
    Andriy.age = 17;
    Andriy.height = 185;
    Andriy.weight = 70;
    Andriy.Adress.city = "Lviv";
    Andriy.Adress.street = "Levandivska";
    cout << "Struct - Student\n - Name: " << Andriy.name << "\n - Surame: " << Andriy.surname << "\n - Age: " << Andriy.age << "\n - Height: " << Andriy.height << "\n - Weight: " << Andriy.weight << "\n - City: " << Andriy.Adress.city << "\n - Street: " << Andriy.Adress.street;
}