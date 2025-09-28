
#include "09_OOP.hh"

/**
 *  > 객체 지향 프로그래밍 (Object Oriented Programming, OOP)
 * 
 *  - 절차적 프로그래밍의 단점을 극복하기 위해 제안된 프로그래밍 패러다임 중의 하나
 *  - 클래스와 객체를 기반으로 작성함.
 * 
 *  > 특징
 * 
 *  - 캡슐화 
 *  - 추상화  
 *  - 상속  
 *  - 다형성 
 * 
 *  > 클래스 (class)
 * 
 *  - 객체 (object)가 생성되기 위한 틀
 *  - 멤버 변수 (데이터)를 가짐
 *  - 멤버 함수 (함수,동작)를 가짐
 *  - 데이터와 함수 은닉 가능함
 *  - 인터페이스 공개 가능
 * 
 *  > 객체 (object)
 * 
 *  - 클래스로부터 생성된 실체
 *  - 객체는 개별적으로 관리되며, 원하는 만큼 생성 가능함.
 *  - 객체를 통해 클래스에 정의된 멤버 함수 호출, 멤버 변수 접근 가능 (즉, 접근하려면 객체가 필요함)
 *  
 *  > 접근 지정자 (access specifier)
 * 
 *  - 클래스 멤버에 대한 접근 권한을 지정함.
 *  - public : 클래스 외부에서 접근 가능
 *  - private : 클래스 내부에서만 접근 가능 (default)
 *  - protected : 상속된 클래스에서 접근 가능
 *  
 *  > 생성자 (constructor)
 * 
 *  - 객체가 생성될 때 자동으로 호출되는 특수한 멤버 함수
 *  - 객체의 초기화를 담당함.
 *  - 클래스 이름과 동일하며, 반환형이 없음
 *  - 오버로딩 가능 (매개변수에 따라 여러 개 정의 가능)
 *  - 생성자 위임 가능 (다른 생성자를 호출하여 초기화 작업을 수행)
 *  
 *  > 소멸자 (destructor)
 * 
 *  - 객체가 소멸될 때 자동으로 호출되는 특수한 멤버 함수
 *  - 객체가 사용하던 자원을 해제하는 역할을 함.
 *  - 클래스 이름 앞에 ~를 붙이며, 반환형이 없음
 *  - 매개변수를 가질 수 없으며, 오버로딩 불가능
 *  
 *  > 오버로딩 (overloading)
 * 
 *  - 생성자는 오버로딩이 가능함. (생성자도 함수이므로)
 *  - 함수 오버로딩과 동일함. 
 *  - 그런데 오버로딩을 많이 쓰면 헷갈릴수가 있음 -> 그래서 생성자 위임을 씀
 * 
 *  > 생성자 위임 (constructor delegation)
 * 
 *  - 다른 생성자를 초기화 리스트 자리에서 호출
 *  - 생성자 초기화 리스트를 사용해서만 가능
 * 
 * 
 * 
 *  > this 포인터
 *  - 클래스 멤버 함수 내에서 현재 객체를 가리키는 포인터
 *  - 멤버 변수와 매개변수 이름이 동일할 때 구분하는 데 사용됨
 *  - 멤버 함수 내에서 명시적으로 현재 객체를 참조할 때 사용됨
 *  
 *  > 동적 할당 (dynamic allocation)
 *  - 런타임에 메모리를 할당하는 방법
 *  - new 연산자를 사용하여 객체를 동적으로 생성함.
 *  - delete 연산자를 사용하여 동적으로 할당된 메모리를 해제함.
 *  
 * 
 */
int main()
{
    player p;   // player 클래스의 객체 p 생성

    p.name = "ocj"; //player 클래스의 멤버 변수 접근
    p.health = 100;
    p.xp = 12;

    cout << "name is "   << p.name   << endl;
    cout << "health is " << p.health << endl;
    cout << "xp is "     << p.xp     << endl;

    player *p_ptr = new player();
    p_ptr -> name = "cano";
    cout << "name is "   << p_ptr->name   << endl;

    //account KimAccount;
    account KimAccount(100,"kim");  //매개변수 있는 생성자 호출함.
    account LeeAccount;             //매개변수 없는 생성자 호출함.

    cout << "name is "   << LeeAccount.name   << endl;

    KimAccount.withdraw(10000);
    KimAccount.deposit(10000);

    account *parkAccount = new account(100,"park"); // 동적 할당
    cout << "name is "   << parkAccount -> name   << endl;
    delete parkAccount;

    return 0;
}