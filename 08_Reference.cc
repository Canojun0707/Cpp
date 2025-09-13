
#include <iostream>

using std::cout;
using std::endl;

void IncrementByreference(int& num);

/**
 *    참조자 (Reference) 
 *  -> 포인터보다 좋은??
 *  -> 변수의 별명 != 변수
 *  
 *  - 기존 변수에 대한 별칭 (alias)을 제공
 *  - 선언 시 반드시 초기화해야 하며, 이후에는 다른 변수로 변경할 수 없음 -> const pointer
 *  - 참조자를 통해 원래 변수에 접근하고 수정할 수 있음 (포인터와 유사)
 *  - null 참조자는 허용되지 않음
 *  - 주로 함수 매개변수로 사용되어, 함수 내에서 원래 변수의 값을 직접 수정할 수 있게 함
 *  - 참조자는 포인터보다 사용이 간편하고, 코드 가독성을 높임
 *  - 참조자는 메모리 주소를 직접 다루지 않기 때문에, 포인터 연산이 필요 없고, 더 안전함
 * 
 */

int main()
{ 
    int value = 42;
    int& ref = value; // ref는 value의 별칭 (alias)
    // => 자동으로 value의 주소를 참조

    cout << "value: " << value << endl; // 42
    cout << "ref: " << ref << endl;     // 42

    ref = 100; // ref를 통해 value의 값을 변경
    cout << "After modifying ref:" << endl;
    cout << "value: " << value << endl; // 100
    cout << "ref: " << ref << endl;     // 100

    IncrementByreference(value); // value의 주소를 전달
    cout << "After Increment function:" << endl;
    cout << "value: " << value << endl; // 101
    cout << "ref: " << ref << endl;     // 101

    return 0;
}

void IncrementByreference(int& num) // num은 value의 별칭 (alias)
{
    num++; // num을 통해 value의 값을 변경
}