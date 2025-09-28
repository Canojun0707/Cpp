
#include <iostream>

using std::cout;
using std::endl;

/**
 * 
 *  > this 포인터
 * 
 *  - 멤버 함수를 호출한 객체의 주소값
 *  - 멤버 함수 내에서 멤버 변수에 접근할 때 사용
 *  
 *  > 주 용도
 *  - 멤버 변수와 지역 변수 이름이 같을 때 구분
 *  - 멤버 함수에서 자기 자신을 반환 (메서드 체이닝)
 *  - 연산자 오버로딩 구현
 * 
 * 
 */

 class player
 {
  private :
    int x,y;
    int speed;
  public :
    player(int x, int y, int speed)
      : x{x}, y{y}, speed{speed}
      {
        cout << this <<endl; //객체가 메모리에 생성된 주소값을 추렭함.
      }
    void setposition(int x, int y)
    {
      //멤버 변수와 매게 변수를 구분할 때 this 사용함.
      // this->x (멤버 변수) = x (매게 변수)
      this->x = x; 
      this->y = y;
    }
    void printposition()
    {
      cout << x << "," << y << endl;
    }
 };
int main()
{
  player *p = new player(10,20,50);
  
  cout << p << endl;

  return 0;
}