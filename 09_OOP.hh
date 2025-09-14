#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class account // account라는 class 선언
{
    public:
        string name;    // 예금주 이름    
        bool withdraw(double amount);
        bool deposit(double amount);
        double getBalance();

        // 파라매터가 없는 생성자는 객체가 생성될 때 자동으로 호출함.
        // 생성자 위임
        account()
          : account(0,"none")   
        {
        }

        // 인자값이 있는 객체를 생성할 때 자동으로 호출함. ( 권장 방법 )
        account(double value, string str) 
            : balance{value}, name{str}     
        {
          cout << "인자값이 있는 생성자 호출됨" << endl;
        }

        ~account()  // 객체가 삭제될 때 자동으로 호출함.
        {
          cout << "소멸자 호출됨" << endl;
        }

    private:
        double balance; // 계좌 잔액
};

class player    // player라는 class 선언 
{
    public:     // public 접근 지정자, 안한다면? => private (default)
        //member variable
        string name;
        int health;
        int xp;

        //생성자 기본 디폴트 선언
        //파라메터에 안넣어도         none, 0, 0저장함
        //ex> player("kim",100,100) -> kim,100,100 저장
        player(string = "none", int healthVal = 0, int xpVal = 0);
        //member function
        void talk(string message);
        bool IsDead();
};


// account 클래스의 함수 정의 
bool account::withdraw(double amount) //출금
{
    balance -= amount;
    cout << "my account is " << balance << endl;
}
bool account::deposit(double amount)  //입금
{
    balance += amount;
    cout << "my account is " << balance << endl;
}
double account::getBalance()
{
    return balance; 
}

player::player(string nameVal, int healthVal, int xpVal)
  : name{nameVal}, health{healthVal}, xp{xpVal}
{

}