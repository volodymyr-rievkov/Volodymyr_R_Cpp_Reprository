#include<iostream>
#include<vector>
#include <functional>
using namespace std;
void* PrintSquare()
{
    cout << "Triangle";
    return nullptr;
}
void* PrintRectangle()
{
    
    return nullptr;
}
void* PrintTriangle()
{
    
    return nullptr;
}
void* PrintPyramid()
{
    
    return nullptr;
}
void* PrintDiamond()
{
    
    return nullptr;
}
void* Exit()
{
    return nullptr;
}
vector<void*> patterns {PrintSquare(), PrintRectangle(), PrintTriangle(), PrintPyramid(), PrintDiamond(), Exit()};
// int ChoosePattern()
// {
//     int action;
//     do
//     {
//         cout << " 1 - Square\n 2 - Rectangle\n 3 - Triangle\n 4 - Pyramid\n 5 - Diamond\n 6 - Exit\nEnter number: ";
//         cin >> action;
//     } while (action != 1 && action != 2 && action != 3 && action != 4 && action != 5 && action != 6);
//     return action;
// }
// bool IsFilled()
// {
//     char choice;
//     bool isFilled;
//     do
//     {
//         cout << "Do you want to fill pattern(y/n): ";
//         cin >> choice;
//     } while (choice != 'y' && choice != 'n');
//     if(choice == 'y')
//     {
//         isFilled = true;
//     }
//     else
//     {
//         isFilled = false;
//     }
//     return isFilled;
// }
int main()
{
    patterns[0];
    // switch(ChoosePattern())
    // {
    //     case 1 : 
    //     case 2 :
    //     case 3 :
    //     case 4 :
    //     case 5 :
    //     case 6 : break;
    // }
    
}
