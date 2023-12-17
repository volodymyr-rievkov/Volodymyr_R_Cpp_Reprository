#include<iostream>
#include<string.h>
using namespace std;

const int workers_amount = 20;
const char* file_name = "text.txt";
FILE* file;
char delete_surname[20];

struct CoWorker
{
    char name[20];
    char surname[20];
    char by_father[20];
    char job[20];
    int birth_year;
    int salary;
};

CoWorker workers_array[workers_amount];

void add_worker()
{
    if(strlen(workers_array[workers_amount - 1].name) == 0)
    {
        file = fopen(file_name, "ab");
        if(file != nullptr)
        {
            int i;
            for(i = 0; i < workers_amount; i++)
            {
                if(strlen(workers_array[i].name) == 0)
                {
                    cout << "Enter name: ";
                    cin >> workers_array[i].name;
                    cout << "Enter surname: ";
                    cin >> workers_array[i].surname;
                    cout << "Enter byfather: ";
                    cin >> workers_array[i].by_father;
                    cout << "Enter job: ";
                    cin >> workers_array[i].job;
                    cout << "Enter birth year: ";
                    cin >> workers_array[i].birth_year;
                    cout << "Enter salary: ";
                    cin >> workers_array[i].salary;
                    cout << endl;
                    break;
                }  
            }
            fwrite(&workers_array[i], sizeof(CoWorker), 1, file);
            fclose(file);
        }
        else
        {
            cout << "Error: File opening is failed" << endl;
        }      
    }
    else
    {
        cout << "Error: List is full" << endl;
    }
}

void print_workers_array()
{
    cout << "-----Workers array-----" << endl;
    cout << endl;
    for(int i = 0; i < workers_amount; i++)
    {
        if(strlen(workers_array[i].name) != 0)
        {
            cout << "---Worker №" << i + 1 << endl;
            cout << " - Name: " << workers_array[i].name << endl;
            cout << " - Surname: " << workers_array[i].surname << endl;
            cout << " - Byfather: " << workers_array[i].by_father << endl;
            cout << " - Job: " << workers_array[i].job << endl;
            cout << " - Birth year: " << workers_array[i].birth_year << endl;
            cout << " - Salary: " << workers_array[i].salary << endl;
            cout << endl;
        }
    }
}

void print_workers_file()
{
    cout << "-----Workers file-----" << endl;
    cout << endl;
    file = fopen(file_name, "rb");
    if(file != nullptr)
    {
        for(int i = 0; i < workers_amount; i++)
        {
            if(fread(&workers_array[i], sizeof(CoWorker), 1, file))
            {
                cout << "---Worker №" << i + 1 << endl;
                cout << " - Name: " << workers_array[i].name << endl;
                cout << " - Surname: " << workers_array[i].surname << endl;
                cout << " - Byfather: " << workers_array[i].by_father << endl;
                cout << " - Job: " << workers_array[i].job << endl;
                cout << " - Birth year: " << workers_array[i].birth_year << endl;
                cout << " - Salary: " << workers_array[i].salary << endl;
                cout << endl;
            }
        }
        fclose(file);   
    }
    else
    {
        cout << "Error: File opening is failed" << endl;
    }   
}

void delete_worker(char* surname)
{
    file = fopen(file_name, "wb");
    if(file != nullptr)
    {
        int i;
        for(i = 0; i < workers_amount; i++)
        {
            if(strcmp(workers_array[i].surname, surname) == 0)
            {
                for(i; i < workers_amount - 1; i++)
                {
                    workers_array[i] = workers_array[i + 1];
                }
                break; 
            }
        }
        for(i = 0; i < workers_amount; i++)
        {
            if(strlen(workers_array[i].name) != 0)
            {
                fwrite(&workers_array[i], sizeof(CoWorker), 1, file);
            }     
        }
        fclose(file);
    }
    else
    {
        cout << "Error: File opening is failed" << endl;
    } 
}

char* get_surname()
{
;
    cout << "Enter surname: ";
    cin >> delete_surname;
    return delete_surname;
}

void add_worker_after_index()
{
    for(int i = 0; i < workers_amount; i++)
    {
        if(strlen(workers_array[i].name) == 0)
        {
            
        }
    }
}

int main()
{
    file = fopen(file_name, "wb");
    fclose(file);
    add_worker();
    add_worker();
    print_workers_array();
    print_workers_file();
    delete_worker(get_surname());
    print_workers_array();
    print_workers_file();
}