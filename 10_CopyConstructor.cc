


#include <iostream>

using std::cout;
using std::endl;

// 복사 생성자 (Copy Constructor)
// => 클래스의 객체를 복사하면서 생성하는 함수
// 객체가 복사 되는 경우
// 1_ 객체를 pass by value (값을 전달)방식으로 함수의 매개변수로 전달할 때
// 2_ 함수에서 value의 형태로 결과를 반환할 때
// 3_ 기존 객체를 기반으로 새로운 객체를 생성할 때
// 객체가 어떤 방식으로 복사될 지 정의해 주어야 함.
// => 사용자가 구현하지 않는 경우 컴파일러에서 자동으로 복사 생성자를 정의함.


//복사 생성자 만들기
class player
{
  public:
    player(int hp, int xp)
      : hp{hp}, xp{xp}
    {
      cout << "생성자 호출됨" << endl;
    }

    player(const player& source)        // 복사 생성자 
      : hp{source.hp}, xp{source.xp}    // 복사한 객체의 값을 참조함. (안하면 멤버 변수 값은 쓰레기값)
    {
      cout << "복사 생성자 호출됨" << endl;
    }
    void print()
    {
      cout << hp << " " << xp << endl;
    }

  private:
    int hp;
    int xp;
};
 
void print_information(player &p)
{
  p.print();
}
int main()
{
  // 순서
  // 1. 복사 생성자 호출
  // 2. 복사한 객체의 값을 참조

  player p1{100, 200};  // 생성자 호출
  player p2{p1};        // 복사 생성자 호출

  print_information(p1);
  print_information(p2);

  p2.print();
}
