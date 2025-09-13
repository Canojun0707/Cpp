
#include <iostream>

using std::cout;
using std::endl;

// 함수 (Function)

// 함수 선언 (Function Declaration)
int add(int a, int b);                 // a, b는 매개변수 (Parameter)
void logMessage(char* message);  // 반환값이 없는 함수
void print_array(int arr[], int size); // 배열을 출력하는 함수

int main()
{
    // 함수 호출 (Function Call)
    int result = add(10, 20); // 10, 20은 인수 (Argument)
    int array[] = {1, 2, 3, 4, 5};
    int array_size = sizeof(array) / sizeof(array[0]);
    
    cout << "result: " << result << endl;

    logMessage("hello function");
    print_array(array, array_size);
    
    return 0;
}

// 함수 정의 (Function Definition)
int add(int a, int b) // a, b는 매개변수 (Parameter)
{
    return a + b; // 반환값 (Return Value)
}

void logMessage(char* message) // 반환값이 없는 함수
{
    cout << "Log: " << message << endl;
}

void print_array(int arr[], int size) // 배열을 출력하는 함수
{
    for (int i = 0; i < size; i++)
    {
        cout << "arr[" << i << "] : " << arr[i] << endl;
    }
}