

#include <iostream>

using std::cout;
using std::endl;

// 조건문 (Conditional Statement)
int main()
{
    int number = 10;

    if (number > 0)       cout << "number는 양수입니다." << endl;
    
    
    if (number % 2 == 0)  cout << "number는 짝수입니다." << endl;
    else                  cout << "number는 홀수입니다." << endl;
    
    switch(number)
    {
        case 5 :  cout << "number는 5입니다." << endl;  break;
        case 10:  cout << "number는 10입니다." << endl; break;
        case 15:  cout << "number는 15입니다." << endl; break;
        default:  cout << "number는 5, 10, 15가 아닙니다." << endl; break;
    }
    return 0;
}