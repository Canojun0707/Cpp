
#include "09_OOP.hh"

int main()
{
    player p;   // player 클래스의 객체 p 생성

    p.name = "ocj";
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