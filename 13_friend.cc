

#include <iostream>

using std::cout;
using std::endl;



/**
 *  > friend 클래스
 * 
 *  - private 멤버에 대해 접근을 허용할 특정 함수나 클래스를 선언할 때 사용
 *  - 비대칭 구조 : A가 B의 freind라고 B가 A의 friend는 아님.
 *  - 전이 되지 않음 : A가 B의 friend이고, B가 C의 friend라고 해서 A가 C의 friend는 아님
 * 
 * 
 * 
 */

 class Engine {
private:
    int rpm;
public:
    Engine(int rpm) : rpm(rpm) {}
    friend class Car;   // Car는 Engine의 private 멤버에 접근 가능
};

class Car {
public:
    void showEngine(const Engine& e) {
        cout << "Engine RPM: " << e.rpm << endl; // private 멤버에 직접 접근 가능
    }
};

int main() {
    Engine e(5000);
    Car c;
    c.showEngine(e);  // Engine RPM: 5000
}