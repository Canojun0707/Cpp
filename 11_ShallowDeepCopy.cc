

#include <iostream>

using std::cout;
using std::endl;

/**
 * 
 *  > 복사 생성자
 * 
 *  - 객체가 복사될 떄는, 기존 객체를 기반으로 새로운 객체가 생성됨
 *  - 객체가 복사되는 경우
 *  - 어떻게 복사 될지 정의해 주어야함 ( 중요 )
 *  - 포인터 타입의 멤버 변수가 존재할 때 주의해야함.
 *  - 기본 복사 생성자는 포인터 타입의 변수 또한 복사하여 대입됨.
 *    즉, 포인터가 가리키는 데이터의 복사가 아닌 포인터 주소값의 복사
 * 
 *  > 얕은 복사 ( shallow copy )
 * 
 *  - 자동 생성되는 복사 생성자는 "얕은 복사" 수행.
 *  - 만약 포인터 타입의 멤버 변수가 존재한다면, 포인터가 가리키는 데이터의 복사가 아닌 포인터 주소값의 복사 
 *  - 즉, 두 객체의 포인터 멤버 변수가 동일한 메모리 주소를 가리키게 됨.
 *  - 두 객체가 동일한 메모리 주소를 가리키게 되면, 한 객체가 소멸될 때 해당 메모리를 해제하게 되고,
 *    다른 객체가 해당 메모리에 접근하게 되면 정의되지 않은 동작이 발생함.
 *  - 즉, 댕글링 포인터 발생 가능.
 *  - 이러한 문제점을 해결하는 것은 => 깊은 복사임.
 * 
 *  > 깊은 복사 ( deep copy )
 * 
 *  - 주소값을 복사하는 것이 아닌, 데이터를 복사하여 복사 생성하는 방식임.
 *  - 즉, 복사 생성자가 새로운 힙 공간을 할당한 뒤 동일한 데이터를 복사함. 
 *  
 * 
 */
class shallow
{
  private :
    int *data;
  
  public:
    shallow(int d)    //생성자
    : data(new int(d)) 
    {}
    shallow(const shallow &source);   // 복사 생성자
    ~shallow()    // 소멸자
    { 
      delete data; 
    }
};

class deep
{
  private :
    int *data;
  
  public:
    deep(int d)    //생성자
    : data(new int(d)) 
    {}
    deep(const deep &source);   // 복사 생성자
    ~deep()    // 소멸자
    { 
      delete data; 
    }
};
int main()
{
  shallow obj1(100);
  shallow obj2 = obj1; // 복사 생성자 호출

  // obj1, obj2 객체는 동일한 메모리 주소를 가리킴
  // main함수가 끝날 때 obj1, obj2 객체가 소멸됨
  // 근데 두 객체가 동일한 메모리 주소를 가리키기 때문에 똑같은 메모리를 두번 delete 하는 오류 생김

  return 0;
}

// 얕은 복사 생성자
shallow::shallow(int d)
{
  data = new int; // 동적 메모리 할당
  *data = d;
}

shallow::shallow(const shallow &source)
  : data(source.data)  // source 객체의 data에 저장된 [주소값]이 현재 객체의 data에 복사됨.
{
  cout << "Copy Constructor, Shallow"<<endl;  
}

// 소멸자 중복 생성자
shallow::~shallow()
{
  delete data;
  cout<< "Destructor called" << endl;
}

// 생성자
deep::deep(int d)
{
  data = new int;
  *data = d;
}

//소멸자
deep::~deep()
{
  delete data;
  cout << "free storage" << endl;
}

deep::deep(const deep &source)
{
  data = new int;
  *data = *source.data; // source 객체의 데이터값을 새로운 힙 메모리를 할당해 복사함.
  cout << "Copy Constructor, Deep" << endl;
}
