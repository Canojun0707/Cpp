
#include <iostream>

using std::cout;
using std::endl;

// 반복문 (Loop Statement)
int main()
{
    // for loop
    cout << "for loop" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "i: " << i << endl;
    }

    // while loop
    cout << "while loop" << endl;
    int j = 0;
    while (j < 5)
    {
        cout << "j: " << j << endl;
        j++;
    }

    // do-while loop
    cout << "do-while loop" << endl;
    int k = 0;
    do
    {
        cout << "k: " << k << endl;
        k++;
    } while (k < 5);

    return 0;
}