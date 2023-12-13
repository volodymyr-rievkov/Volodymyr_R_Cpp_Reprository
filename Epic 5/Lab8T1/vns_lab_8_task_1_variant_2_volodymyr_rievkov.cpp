#include<iostream>
#include<string>
using namespace std;

const int max_name_length = 20;
const int max_job_length = 15;
const int workers_amount = 20;

struct CoWorker
{
    char name[max_name_length];
    char surname[max_name_length];
    char by_father[max_name_length];
    char job[max_job_length];
    int birth_year;
    int salary;
};

void add_worker(CoWorker array[], FILE* file)
{
    file = fopen("text.txt", "wb");
    if(file != NULL)
    {
        for(int i = 0; i < workers_amount; i++)
        {
            if(array[i].name == " ")
            {
                cout << "Enter name: ";
                cin >> array[i].name;
                cout << "Enter surname: ";
                cin >> array[i].surname;
                cout << "Enter byfather: ";
                cin >> array[i].by_father;
                cout << "Enter job: ";
                cin >> array[i].job;
                cout << "Enter birth year: ";
                cin >> array[i].birth_year;
                cout << "Enter salary: ";
                cin >> array[i].salary;
                fwrite(&array[i], sizeof(CoWorker), 1, file);
                fclose(file);
                break;
            }
        }
    }
    else
    {
        cout << "Error: File opening is failed" << endl;
        fclose(file);
    } 
}

int main()
{
    FILE* file;
    CoWorker workers_array[workers_amount];
    add_worker(workers_array, file);
}