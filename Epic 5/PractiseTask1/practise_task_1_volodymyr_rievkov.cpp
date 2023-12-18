#include<iostream>
using namespace std;

FILE* file;
const char* file_name = "text.txt";
const char* content = "There are many variations of passages of Lorem Ipsum available,\n"
                        "but the majority have suffered alteration in some form, by injected humour,\n"
                        "or randomised words which don't look even slightly believable.\n"
                        "If you are going to use a passage of Lorem Ipsum,\n"
                        "you need to be sure there isn't anything embarrassing hidden in the middle of text.\n"
                        "All the Lorem Ipsum generators on the Internet tend to repeat predefined chunks as necessary,\n"
                        "making this the first true generator on the Internet. It uses a dictionary of over 200 Latin words,\n"
                        "combined with a handful of model sentence structures, to generate Lorem Ipsum which looks reasonable.\n"
                        "The generated Lorem Ipsum is therefore always free from repetition, injected humour, or non-characteristic words etc.";

enum FileResult
{
    Success,
    Failure
};

FileResult write_to_file(const char* file_name, const char* content)
{
    file = fopen(file_name, "wb");
    if(file == nullptr)
    {
        return Failure;
    }
    else
    {
        fprintf(file, content);
        fclose(file);
        return Success;
    }
}

void print_file(const char* file_name)
{
    file = fopen(file_name, "r");
    if(file != nullptr)
    {
        cout << endl << "File content: " << endl << endl;
        char buffer[1024];
        while(fgets(buffer, sizeof(buffer), file))
        {
            cout << buffer;
        }
        cout << endl;
        fclose(file);
    }
    else
    {
        cout << "Error: File  reading is failed" << endl;
    }
}

int main()
{
    if(write_to_file(file_name, content) == Success)
    {
        cout << endl << "Content is successfully written" << endl;
        print_file(file_name);
    }
    else
    {
        cout << "Error: Content writing is failed" << endl;
    }
}