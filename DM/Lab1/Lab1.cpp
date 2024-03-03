#include<iostream>
using namespace std;

struct Element
{
    char name;
    int value;
};

void set_value(Element &e)
{
    bool loop = false;
    do
    {
        cout << "Enter '" << e.name <<"' value: ";
        cin >> e.value;
        if(e.value == 0 || e.value == 1)
        {
            loop = false;  
        }
        else
        {
            cout << "Error: Wrong value!" << endl;
            loop = true;   
        }
    } while (loop);  
}

void print_expression()
{
    cout << "     (x v (y v z))→(!x v (!y v !z))     " << endl;
}

bool logic_or(int value_1, int value_2)
{
    if((value_1 + value_2) == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main()
{
    Element e1 = {'x'};     
    Element e2 = {'y'};
    Element e3 = {'z'};
    set_value(e1);
    set_value(e2);
    set_value(e3);
    print_expression();
    int result_1 = 0;
    int result_2 = 0;
    cout << "y v z = ";
    if(logic_or(e2.value, e3.value))
    {
        result_1 = 1;
    }
    else
    {
        result_1 = 0;
    }
    cout << result_1 << endl;
    cout << "x v (y v z) = ";
    if(logic_or(e1.value, result_1))
    {
        result_1 = 1;
    }
    else
    {
        result_1 = 0;
    }
    cout << result_1 << endl;
    cout << "!y v !z = ";
    if(logic_or(!e2.value, !e3.value))
    {
        result_2 = 1;
    }
    else
    {
        result_2 = 0;
    }
    cout << result_2 << endl;
    cout << "!x v (!y v !z) = ";
    if(logic_or(!e1.value, result_2))
    {
        result_2 = 1;
    }
    else
    {
        result_2 = 0;
    }
    cout << result_2 << endl;
    cout << "(x v (y v z))→(!x v (!y v !z)) = ";
    if(result_1 == 1 && result_2 == 0)
    {
        cout << "0" << endl;
    }
    else
    {
        cout << "1" << endl;
    } 
}
