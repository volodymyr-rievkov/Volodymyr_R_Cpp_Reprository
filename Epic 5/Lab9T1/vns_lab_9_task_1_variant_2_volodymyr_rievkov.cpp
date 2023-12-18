#include<iostream>
#include<string.h>
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

void init_file()
{
    file_1 = fopen(file_1_name, "w");
    if(file_1 != nullptr)
    {
        fprintf(file_1, file_content);
        fclose(file_1);
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
        char buffer[1024];
        while(fgets(buffer, sizeof(buffer), file))
        {
            cout << buffer;
        }
        cout << endl << endl;
        fclose(file);
    }
    else
    {
        cout << "Error: File opening is failed" << endl;
    }
}

void add_a_strings_to_file(const char* file_1_name, const char* file_2_name)
{
    file_1 = fopen(file_1_name, "r");
    file_2 = fopen(file_2_name, "w");
    if(file_1 != nullptr && file_2 != nullptr)
    {
        char first_line[1024];
        while(fgets(first_line, sizeof(first_line), file_1))
        {
            if(first_line[0] == 'a' || first_line[0] == 'A')
            {
                fprintf(file_2, first_line);
            }
        }
        fclose(file_1);
        fclose(file_2);
    }
    else
    {
        cout << "Error: File opening is failed" << endl;
    }
}

int main()
{
    init_file();
    cout << "File 1: " << endl;
    print_file(file_1, file_1_name);
    cout << "File 2: " << endl;
    add_a_strings_to_file(file_1_name, file_2_name);
    print_file(file_2, file_2_name);
}