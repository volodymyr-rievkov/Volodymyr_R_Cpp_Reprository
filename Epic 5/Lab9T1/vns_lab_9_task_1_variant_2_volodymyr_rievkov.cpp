#include<iostream>
#include<string>
using namespace std;

FILE* file_1;
FILE* file_2;
const char* file_1_name = "file_1.txt";
const char* file_2_name = "file_2.txt";
const char* file_content = "Lorem Ipsum is simply dummy text of the printing and typesetting industry.\n"
                            "Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when\n"
                            "an unknown printer took a galley of type and scrambled it to make a type specimen book.\n"
                            "It has survived not only five centuries, but\n"
                            "also the leap into electronic typesetting, remaining essentially unchanged.\n"
                            "It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages,\n"
                            "and more recently with desktop publishing software like\n"
                            "Aldus PageMaker including versions of Lorem Ipsum.\0";

void init_file(FILE* file, const char* file_name, const char* file_content)
{
    file = fopen(file_name, "w");
    if(file != nullptr)
    {
        fprintf(file, file_content);
        fclose(file);
    }
    else
    {
        cout << "Error: File opening is failed" << endl;
    }
}

void print_file(FILE* file, const char* file_name)
{
    file = fopen(file_name, "r");
    if(file != nullptr)
    {
        // string line;
        // while(getline(file, line))
        // {
        //     cout << line << endl;
        // }
        fclose(file);
    }
    else
    {
        cout << "Error: File opening is failed" << endl;
    }
}

void add_a_strings_to_file(FILE* file_1, const char* file_1_name, FILE* file_2, const char* file_2_name)
{
    file_1 = fopen(file_1_name, "r");
    file_2 = fopen(file_2_name, "w");
    if(file_1 != nullptr && file_2 != nullptr)
    {
        //while(fgets())
    }
    else
    {
        cout << "Error: File opening is failed" << endl;
    }
}

int main()
{
    init_file(file_1, file_1_name, file_content);
    print_file(file_1, file_1_name);
}