#include<iostream>
using namespace std;

const int max_name_length = 20;
const int max_job_length = 15;

struct CoWorker
{
    char name[max_name_length];
    char surname[max_name_length];
    char by_father[max_name_length];
    char job[max_job_length];
    int birth_year;
    int salary;
};

int main()
{
    FILE* file;
    CoWorker cw;
}