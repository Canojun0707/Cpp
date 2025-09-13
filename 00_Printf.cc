
#include <stdio.h>  //c style input/output
#include <iostream> //c++ style input/output 

using std::cout;
using std::endl;

// c++ build process
// compiler      => souce code => object code
// linker        => object code => executable code
// Test & Debung => find bugs & fix bugs
// 소스코드 -> 컴파일러 -> 오브젝트 코드(목적파일) -> 링커 -> 실행파일

int main() 
{
    int number = 10;
    cout << "Hello, World! " << number << endl;
    printf("Hello, World! %d\n", number);
    return 0;
}
