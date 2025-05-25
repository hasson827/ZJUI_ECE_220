#include <iostream>
using namespace std;

class Animal{
public:
    void eat(){cout << "I'm eating general food." << endl;}
    virtual void drink(){cout << "I'm drinking general water." << endl;}
};

class Cat : public Animal{
public:
    void eat(){cout << "I'm eating cat food." << endl;}
    void drink(){cout << "I'm drinking cat water." << endl;}
};

void eat_drink(Animal *a){
    a->eat();
    a->drink();
}

int main(){
    Animal *a = new Animal();
    Cat *c = new Cat();
    eat_drink(a);
    eat_drink(c);
    delete a;
    delete c;
    return 0;
}