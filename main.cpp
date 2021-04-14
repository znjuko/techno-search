//
// Created by paccbet on 13.04.2021.
//
#include <iostream>

using namespace std;

class iInterface
{
  public:
    virtual ~iInterface()
    {
        std::cout << "i del" << std::endl;
    };

    virtual void DoSomething() = 0;
};

class CClass1 : public iInterface
{
  public:
    CClass1() = default;

    ~CClass1() override = default;

    void DoSomething() override
    {
        std::cout << "a" << std::endl;
    };
};

class CClass2 : public iInterface
{
  public:
    CClass2() = default;

    ~CClass2() override
    {
        std::cout << "b del" << std::endl;
    };

    void DoSomething() override
    {
        std::cout << "b" << std::endl;
    };
};

class CClass3
{
  public:
    void DoSomething(iInterface *pTarget)
    {
        pTarget->DoSomething();
    }

    iInterface v()
    {
        return CClass1();
    }
};

int main()
{
    iInterface *pAgent = new CClass1(); //объект класса CClass1

    CClass3 manipulator;

    manipulator.DoSomething(pAgent); //манипулятор запустит метод агента,
    //причем запустится версия метода, описанная в классе CClass1

    delete pAgent;

    iInterface *pAgent1 = new CClass2(); //объект класса CClass2

    manipulator.DoSomething(pAgent1); //манипулятор запустит метод агента,
    //причем запустится версия метода, описанная в классе CClass2

    delete pAgent1;

    return 0;
}