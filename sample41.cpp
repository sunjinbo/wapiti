// 强制类型转换

#include <iostream>

using namespace std;

class Plant
{
public:
    virtual const char* getName() const = 0;
};

class Flower : public Plant
{
public:
    Flower()
    {
        cout << "Flower constructor" << endl;
    }

    ~Flower() {
        cout << "Flower destructor" << endl;
    }

    const char* getName() const
    {
        return "This is a flower!";
    }
};

class Animal
{
private:
    const char* mName;

public:
    virtual const char* getName() const = 0;

protected:
    Animal(const char* name)
    {
        cout << "Animal constructor" << endl;
        mName = name;
    }

    ~Animal() {
        cout << "Animal constructor" << endl;
    }
};

class Dog : public Animal
{
public:
    Dog() : Animal("dog")
    {
        cout << "Dog constructor" << endl;
    }

    ~Dog() {
        cout << "Dog destructor" << endl;
    }

    const char* getName() const
    {
        return "This is a dog!";
    }
};

class Pig : public Animal
{
public:
    Pig() : Animal("pig")
    {
        cout << "Pig constructor" << endl;
    }

    ~Pig() {
        cout << "Pig destructor" << endl;
    }

    const char* getName() const
    {
        return "This is a pig!";
    }
};

void static_cast_test()
{
    Animal* animal = new Dog();
    Dog* dog = static_cast<Dog*>(animal);
    cout << dog->getName() << endl;
    delete dog;
    animal = NULL;
    dog = NULL;

    // Plant* plant = new Plant();
    // animal = static_cast<Animal*>(plant); // compile error
}

void dynamic_cast_test()
{
    Plant* plant = new Flower();
    Dog* dog = dynamic_cast<Dog*>(plant); // run-time error
    if (dog != NULL)
    {
        cout << dog->getName() << endl;
    }
}

void const_cast_test()
{
    const int constant = 21;
    const int* const_p = &constant;
    int* modifier = const_cast<int*>(const_p);
    *modifier = 7;
}

void reinterpret_cast_test()
{
    Dog* dog = new Dog();
    Pig* pig = reinterpret_cast<Pig*>(dog);
    cout << pig->getName() << endl;
}

int main()
{
    static_cast_test();
    dynamic_cast_test();
    const_cast_test();
    reinterpret_cast_test();

    return 0;
}
