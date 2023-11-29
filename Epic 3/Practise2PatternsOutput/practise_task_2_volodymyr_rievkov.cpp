#include<iostream>
using namespace std;
int sideSize;
void GetSideSize()
{
    cout << "Enter size: ";
    cin >> sideSize;
}
int ChoosePattern()
{
    int action;
    do
    {
        cout << " 1 - Square\n 2 - Rectangle\n 3 - Triangle\n 4 - Pyramid\n 5 - Diamond\n 6 - Exit\nEnter number: ";
        cin >> action;
    } while (action != 1 && action != 2 && action != 3 && action != 4 && action != 5 && action != 6);
    return action;
}
bool IsFilled()
{
    char choice;
    bool isFilled;
    do
    {
        cout << "Do you want to fill pattern(y/n): ";
        cin >> choice;
    } while (choice != 'y' && choice != 'n');
    if(choice == 'y')
    {
        isFilled = true;
    }
    else
    {
        isFilled = false;
    }
    cout << endl;
    return isFilled;
}
void PrintSquare()
{
    GetSideSize();
    if(IsFilled())
    {
        for(int i = 0; i < sideSize; i++)
        {
            for(int y = 0; y < sideSize; y++)
            {
                cout << "* ";
            }
            cout << endl;
        }
    }
    else
    {
        for(int i = 0; i < sideSize; i++)
        {
            for(int y = 0; y < sideSize; y++)
            {
                if(y == 0 || i == 0 || y == sideSize - 1 || i == sideSize - 1)
                {
                    cout << "* ";
                }
                else
                {
                    cout << "  ";
                }
            }
            cout << endl;
        }
    }  
    cout << endl;
}
void PrintRectangle()
{
    int biggerSidesize = sideSize * 2;
    GetSideSize();
    if(IsFilled())
    {
        for(int i = 0; i < sideSize; i++)
        {
            for(int y = 0; y < biggerSidesize; y++)
            {
                cout << "* ";
            }
            cout << endl;
        }
    }
    else
    {
        for(int i = 0; i < sideSize; i++)
        {
            for(int y = 0; y < biggerSidesize; y++)
            {
                if(y == 0 || i == 0 || y == biggerSidesize - 1 || i == sideSize - 1)
                {
                    cout << "* ";
                }
                else
                {
                    cout << "  ";
                }
            }
            cout << endl;
        }
    }  
    cout << endl;

}
void PrintTriangle()
{
    
}
void PrintPyramid()
{
    
}
void PrintDiamond()
{
    
}
void Exit()
{

}
int main()
{
    PrintRectangle();
}