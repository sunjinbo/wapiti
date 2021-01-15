// 析构函数

#include <iostream>
#include <cstring>

using namespace std;

class Furniture
{
public:
    virtual string getName() = 0;
};

class Desk
{
public:
    string getName()
    {
        return "desk";
    }
};

class Chair
{
public:
    string getName()
    {
        return "chair";
    }
};

class House
{
private:
    Desk* desk;
    Chair* chair;

public:
    House();
    ~House();
};

House::House()
{
    desk = new Desk();
    chair = new Chair();
}

House::~House()
{
    delete desk;
    desk = NULL;
    delete chair;
    chair = NULL;
}

int main()
{
    House* house = new House();
    delete house;
    house = NULL;

    return 0;
}