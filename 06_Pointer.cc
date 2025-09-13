

#include <iostream>

using std::cout;
using std::endl;

// 포인터 (Pointer)

int main()
{
    //포인터 선언 및 초기화
    int var = 42;        // 정수형 변수
    int* ptr = &var;     // 변수의 주소를 저장하는 포인터

    cout << "var의 값: " << var << endl;             // 변수의 값 출력
    cout << "var의 주소: " << &var << endl;          // 변수의 주소 출력
    cout << "ptr이 가리키는 값: " << *ptr << endl;    // 포인터가 가리키는 값 출력
    cout << "ptr의 값 (var의 주소): " << ptr << endl; // 포인터의 값 출력

    // 포인터를 사용하여 변수의 값을 변경
    *ptr = 100;
    cout << "포인터를 통해 변경된 var의 값: " << var << endl;

    /**
     * 동적 메모리 할당 (dynamic memory allocation)
     *  
     * 프로그램의 실행 도중 얼마나 많은 메모리가 필요한지 모를 때 사용
     * 큰 데이터를 저장해야 하는 경우
     * 언제 메모리가 할당되고 해제되어야 할지를 직접 제어해야 하는경우 
     * 
     * 댕글링 포인터 (Dangling Pointer)
     *  -> 이미 해제된 메모리를 가리키는 포인터
     */

    // c에서의 동적 메모리 할당
    // malloc => 힙 메모리에 변수 할당
    // free   => 힙 메모리에 할당된 변수 해제
    int* cStylePtr = (int*)malloc(sizeof(int)); // 정수형 변수 크기만큼 메모리 할당
    if (cStylePtr == nullptr) // 메모리 할당 실패 시 nullptr 반환
    {
        cout << "메모리 할당 실패" << endl;
        return 1; // 프로그램 종료
    }
    *cStylePtr = 99; // 할당된 메모리에 값 저장
    cout << "cStylePtr이 가리키는 값: " << *cStylePtr << endl;
    free(cStylePtr); // 할당된 메모리 해제
    cStylePtr = nullptr; // 댕글링 포인터 방지

    // c++에서의 동적 메모리 할당
    // new    => 힙 메모리에 변수 할당
    // delete => 힙 메모리에 할당된 변수 해제
    int* dynamicPtr = new int(55); // 힙 메모리에 정수형 변수 할당
    if (dynamicPtr == nullptr) // 메모리 할당 실패 시 nullptr 반환
    {
        cout << "메모리 할당 실패" << endl;
        return 1; // 프로그램 종료
    }
    cout << "dynamicPtr이 가리키는 값: " << *dynamicPtr << endl;
    delete dynamicPtr; // 동적 메모리 해제
    dynamicPtr = nullptr; // 댕글링 포인터 방지

    // 배열의 동적 메모리 할당
    int size = 5;
    int* arrayPtr = new int[size]; // 크기가 size인 정수형 배열 동적 할당
    
    for (int i = 0; i < size; i++)  
    {
        arrayPtr[i] = i * 10; // 배열에 값 저장
    }
    cout << "arrayPtr이 가리키는 배열 값: ";
    for (int i = 0; i < size; i++)
    {
        cout << arrayPtr[i] << " "; // 배열 값 출력
    }
    cout << endl;
    delete[] arrayPtr; // 동적 배열 메모리 해제
    arrayPtr = nullptr; // 댕글링 포인터 방지

    //array pointer
    int arr[3] = {10, 20, 30};
    int (*arrPtr)[3] = &arr; // 크기가 3인 정수형 배열을 가리키는 포인터
    
    cout << *arr << endl;        // 배열의 첫 번째 요소 출력
    cout << *(arr + 1) << endl;    // 배열의 두 번째 요소 출력
    cout << *(arr + 2) << endl;    // 배열의 세 번째 요소 출력

    cout << *(*arrPtr) << endl; // 배열의 첫 번째 요소 출력
    cout << *(*arrPtr + 1) << endl; // 배열의 두 번째 요소 출력
    cout << *(*arrPtr + 2) << endl; // 배열의 세 번째 요소 출력

    //const pointer
    int value = 500;
    const int* constPtr = &value; // 값이 변하지 않는 정수형을 가리키는 포인터
    //*constPtr = 600; //오류: const 포인터는 값을 변경할 수 없음
    cout << "constPtr이 가리키는 값: " << *constPtr << endl;
    value = 600; // 원래 변수의 값은 변경 가능
    cout << "value의 변경된 값: " << value << endl;
    cout << "constPtr이 가리키는 값: " << *constPtr << endl;
    
    //dangling pointer
    int* danglingPtr = new int(42); // 동적 메모리 할당
    delete danglingPtr;              // 메모리 해제
    // cout << *danglingPtr << endl;  // 위험: 이미 해제된 메모리를 참조
    danglingPtr = nullptr;           // 댕글링 포인터 방지
    if (danglingPtr != nullptr)
    {
        cout << *danglingPtr << endl; // 안전: nullptr 체크
    }
    else
    {
        cout << "danglingPtr은 더 이상 유효하지 않습니다." << endl;
    }

    return 0;
}