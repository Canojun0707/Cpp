

#include <iostream>

using std::cout;
using std::endl;

void double_data(int* int_ptr)
{
    *int_ptr *= 2;
}

int* largest_data(int* int_ptr1, int* int_ptr2)
{
    if (*int_ptr1 > *int_ptr2)  return int_ptr1;
    else                        return int_ptr2;
}
//pass by reference (주소값을 전달)
int main()
{
    int value = 10;

    //before
    cout << "Before: " << value << endl;
    double_data(&value); // value의 주소를 전달
    
    //after
    cout << "After: " << value << endl;

    // 포인터 주소값을 반환
    // => 지역변수 반환은 위험함. 지역변수는 함수가 끝나면 메모리에서 해제됨.
    // => 동적 메모리 할당을 하거나, 전역변수를 사용해야함.

    int a = 100;
    int b = 200;
    int* larger = largest_data(&a, &b);
    cout << "Larger value: " << *larger << endl;

    return 0;
}