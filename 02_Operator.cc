

#include <iostream>

using std::cout;
using std::endl;
using std::boolalpha;

// 연산자 (Operator)
int main()  
{
    int a = 10;
    int b = 20;

    // 산술 연산자
    cout << "a + b = " << a + b << endl; // 덧셈
    cout << "a - b = " << a - b << endl; // 뺄셈
    cout << "a * b = " << a * b << endl; // 곱셈
    cout << "b / a = " << b / a << endl; // 나눗셈
    cout << "b % a = " << b % a << endl; // 나머지

    // 복합 대입 연산자
    a += 5; // a = a + 5
    cout << "a += 5 => a = " << a << endl;
    a -= 3; // a = a - 3
    cout << "a -= 3 => a = " << a << endl;
    a *= 2; // a = a * 2
    cout << "a *= 2 => a = " << a << endl;
    a /= 4; // a = a / 4
    cout << "a /= 4 => a = " << a << endl;
    a %= 3; // a = a % 3
    cout << "a %= 3 => a = " << a << endl;

    // 증감 연산자
    cout << "++a = " << ++a << endl; // 전위 증가
    cout << "a++ = " << a++ << endl; // 후위 증가
    cout << "--a = " << --a << endl; // 전위 감소
    cout << "a-- = " << a-- << endl; // 후위 감소
    cout << "현재의 a 값: " << a << endl;

    // 비교 연산자
    cout << boolalpha; // bool 값을 true/false로 출력
    cout << "a == b : " << (a == b) << endl; // 같음
    cout << "a != b : " << (a != b) << endl; // 같지 않음
    cout << "a > b : "  << (a > b)  << endl; // 큼
    cout << "a < b : "  << (a < b)  << endl; // 작음
    cout << "a >= b : " << (a >= b) << endl; // 크거나 같음
    cout << "a <= b : " << (a <= b) << endl; // 작거나 같음

    // 논리 연산자
    bool x = true;
    bool y = false;
    cout << "x && y : " << (x && y) << endl; // AND
    cout << "x || y : " << (x || y) << endl; //
    cout << "!x : "    << (!x)    << endl; // NOT
    cout << "!y : "    << (!y)    << endl; // NOT

    // 비트 연산자
    int m = 5;  // 0000 0101
    int n = 3;  // 0000 0011
    cout << "m & n = " << (m & n) << endl; // AND  => 0000 0001
    cout << "m | n = " << (m | n) << endl; // OR   => 0000 0111
    cout << "m ^ n = " << (m ^ n) << endl; // XOR  => 0000 0110
    cout << "~m = "   << (~m)    << endl; // NOT  => 1111 1010
    cout << "m << 1 = " << (m << 1) << endl; // 왼쪽 시프트 => 0000 1010
    cout << "m >> 1 = " << (m >> 1) << endl; // 오른쪽 시프트 => 0000 0010

    // 삼항 연산자
    int max = (a > b) ? a : b; // a가 b보다 크면 a, 아니면 b
    cout << "max = (a > b) ? a : b => max = " << max << endl;

    return 0;

}