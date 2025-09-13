
#include <iostream>

using std::cout;
using std::endl;

// array => 연속된 메모리 주소에 저장
// 자료형 만큼 메모리 공간을 할당함.

int main()
{
    // 정수형 배열 선언 및 초기화
    // arr[5] = {0} => arr[0] ~ arr[4] 까지 0으로 초기화
    // arr[10] = {1, 2} => arr[2] ~ arr[9] 까지 0으로 초기화
    // arr[] = {1, 2, 3, 4, 5} => [] 배열 크기를 자동으로 계산
    // 배열의 이름은 배열의 시작 주소를 나타냄 => arr == &arr[0]
    
    int arr[5] = {1, 2, 3, 4, 5};
    int arr_len = sizeof(arr) / sizeof(arr[0]); // 배열의 크기 계산

    // 배열의 각 요소에 접근하여 출력
    for (int i = 0; i < arr_len; i++)
    {
        cout << "arr[" << i << "] : " << arr[i] << endl;
    }
    
    return 0;
}