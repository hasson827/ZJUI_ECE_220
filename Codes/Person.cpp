#include <iostream>
using namespace std;
class Person{
    const char *name;
    unsigned int byear;
public:
    Person *next;
    Person(const char *name, unsigned int byear){
        this->name = name;
        this->byear = byear;
        this->next = NULL;
    }
    Person(const Person &p){
        this->name = p.name;
        this->byear = p.byear;
        this->next = NULL;
    }
    void print(){cout << this->name << ", " << byear << endl;}
};

class LinkedList{
    Person *head;
public:
    LinkedList(){this->head = NULL;} // Constructor
    void print_list();
    void add_at_head(Person &p);
    void add_at_tail(Person &p);
    void del_at_head();
    void del_at_tail();
    ~LinkedList();
};

class Stack{
    Person *top;
public:
    Stack(){this->top = NULL;} // Constructor
    void push(Person &p);
    void pop();
    void print_stack();
    ~Stack();
};

void LinkedList::print_list(){
    Person *current = this->head;
    while (current != NULL){
        current->print();
        current = current->next;
    }
}

void LinkedList::add_at_head(Person &p){
    Person *new_person = new Person(p);
    new_person->next = this->head;
    this->head = new_person;
}

void LinkedList::add_at_tail(Person &p){
    Person *new_person = new Person(p);
    if (this->head == NULL){
        this->head = new_person;
        return;
    }
    Person *current = this->head;
    while (current->next != NULL){
        current = current->next;
    }
    current->next = new_person;
}

void LinkedList::del_at_head()
{
    if (this->head == NULL){return;}
    Person *temp = this->head;
    this->head = this->head->next;
    delete temp;
}

void LinkedList::del_at_tail(){
    if (this->head == NULL){return;}
    if (this->head->next == NULL){
        delete this->head;
        this->head = NULL;
        return;
    }
    Person *current = this->head;
    while (current->next->next != NULL){current = current->next;}
    delete current->next;
    current->next = NULL;
}

LinkedList::~LinkedList(){
    while (this->head != NULL){del_at_head();}
}

void Stack::push(Person &p){
    Person* new_person = new Person(p);
    new_person->next = this->top;
    this->top = new_person;
}

void Stack::pop(){
    if (this->top == NULL){return;}
    Person *temp = this->top;
    this->top = this->top->next;
    delete temp;
}

void Stack::print_stack(){
    Person* current = this->top;
    if (current == NULL){
        cout << "Stack is empty." << endl;
        return;
    }
    while (current != NULL){
        current->print();
        current = current->next;
    }
}

Stack::~Stack(){
    while (this->top != NULL){pop();}
}

int main()
{
    LinkedList list;
    Person p1("Alice", 1990);
    Person p2("Bob", 1985);
    Person p3("Charlie", 2000);

    list.add_at_head(p1);
    list.add_at_tail(p2);
    list.add_at_tail(p3);

    cout << "List after adding persons:" << endl;
    list.print_list();

    list.del_at_head();
    cout << "List after deleting head:" << endl;
    list.print_list();

    list.del_at_tail();
    cout << "List after deleting tail:" << endl;
    list.print_list();

    Stack stack;
    stack.push(p1);
    stack.push(p2);
    cout << "Stack after pushing persons:" << endl;
    stack.print_stack();
    stack.pop();
    cout << "Stack after popping persons:" << endl;
    stack.print_stack();
    stack.pop();
    stack.print_stack();

    return 0;
}