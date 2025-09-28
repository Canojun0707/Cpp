#include <iostream>

using std::cout;
using std::endl;

/**
 * 
 *  > 다형성 ( Polymorphism )
 * 
 *  - Poly (많은) + Morph (형태)
 *  - 정적 바인딩 (compile time)
 *  - 동적 바인딩 (run time)
 *  - 런타임 다형성 : 런타임에서 같은 함수에 대해 다른 의미를 부여 -> 함수의 오버라이딩
 *  - 추상화된 프로그래밍을 가능하게 함
 * 
 *  > 오버라이딩
 *  - 유도 클래스에서 기본 클래스의 함수를 재정의하여 사용하는 것
 *  - 기본 클래스의 함수와 유도 클래스의 함수가 동일한 이름과 인
 * 
 *  > 정적 바인딩
 *
 *  - 컴파일 타임에 함수 호출이 결정됨.
 *  - 유도 클래스와 기본 클래스에 같은 이름과 인자를 갖는 함수가 2개 존재할 때
 *  - 어떤 기준으로 호출할 함수를 결정할까 -> 타입을 기준
 *  - 즉, 컴파일러는 객체의 타입을 보고 호출할 함수를 결정함.
 *  
 *  > 동적 바인딩
 * 
 *  - 런타임시 실제 메모리에 저장된 타입을 기준으로 호출 함수를 결정함.
 *  
 *  > 가상 함수
 * 
 *  - 유도 클래스에서 기본 클래스의 함수를 재정의 또는 오버라이드해 사용할 수 있음
 *  - 오버라이드될 수 있는 함수를 가상 함수라고 함.
 * 
 *  > 가상 함수의 선언, 유도 클래스에서 할일
 * 
 *  - 오버라이드 할 함수를 유도 클래스에서 구현
 *  - 함수 원형과 반환형이 기본 클래스의 가상 함수와 일치해야함.
 *  - 유도 클래스의 함수에서는 virtual 키워드를 넣지 않아도 되지만, 혼동을 피하기 위해 명시
 *  - 유도 클래스에서 함수를 오버라이드 하지 안흥면, 기존과 같이 기본 클래스의 함수가 상속됨.
 */

class entity
{
protected :
  int x,y; //자식 클래스에서 접근 가능하도록 protected로 선언함.

public :
  entity(int x, int y)
    : x{x}, y{y}
  {
    cout << "Entity constructor called" << endl;
  }
  ~entity()
  {
    cout << "Entity destructor called" << endl;
  }
  void showposition()
  {
    cout << x << "," << y << endl;
  }
  void talk()
  {
    cout << "entity talk" << endl;
  }

  // 오버라이딩 될 수 있는 함수
  virtual void move(int dx, int dy)
  {
    x += dx;
    y += dy;
  }
};

class player : public entity
{
  private :
    int hp,xp,speed;
  public :
    player(int x, int y, int speed)
      : entity{x,y}, speed{speed}
    {
      
    }
    ~player()
    {
      cout << "player destructor called" << endl;
    }
    /* // 기존 move 함수
    void move(int dx, int dy)
    {
      x += dx * 2;
      y += dy * 2;
    } */

   // 오버라이딩 된 move 함수
    virtual void move(int dx, int dy) override
    {
      x += dx * 2;
      y += dy * 2;
    }

    void talk()
    {
      cout << "player talk" << endl;
    }
};

int main()
{

  //자료형에 따라 호출되는 함수가 달라짐 -> 정적 바인딩
  player p(10,20,50);
  p.talk();   // 자료형이 player라서 player class의 talk() 호출됨.
  entity e(5,5);
  e.talk();   // entity class의 talk() 호출됨.
  

  entity a = player(1,1,10);

  entity* eptr = new player(1,1,1);
  eptr->talk();
  delete eptr;

  return 0;
}