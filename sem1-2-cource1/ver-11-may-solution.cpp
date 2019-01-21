#include <iostream>

class A {
public:
    A() {printFromConstruct();}
    void work() {printFromWork();}
    virtual ~A() {printFromDestructor();}

    virtual void printFromConstruct() { std::cout << "A";};
    virtual void printFromDestructor() { std::cout << "~A";};
    virtual void printFromWork() { std::cout << "[A]";};
};

class B : public A {
public:
    B() {printFromConstruct();}
    void work() {printFromWork();}
    ~B() {printFromDestructor();}

    virtual void printFromConstruct() { std::cout << "B";};
    virtual void printFromDestructor() { std::cout << "~B";};
    virtual void printFromWork() { std::cout << "[B]";};
};

int main() {
    A* a = new B;
    a->work(); //this->vptr[2](this);
    delete a;
}

//деструктор базового класса должен быть виртуальный во избежание неопроделенного поведения;


/*
//  A* a = new B;
// a->work(); будет вызван A::work(); так как компилятор не знает о динамическом обьявлении

// класс наз обстрактным если у него все методы вирт; обознач ноликом; обозначается чтобы
//помочь компилятору не создавать обьекты абстрактного класса

// a->printFromWork(); метод виртуальный и переопределен в В;
// A:fptr -> [printFromConstruct -> A::printFromConstruct;
//    printFromDestructor ->A::printFromDestructor;
//    printFromWork->A::printFromWork]     --/таблица 1/--

// для В также но все A заменены на В; но эта таблица имеет данный вид только в конце;
//сначала про создании обьекта вызывается конструктор базового класса и таблица будет иметь вид таблицы 1 (см выше)

// базовые классы в наследовательных находятся в начале

// класс В будет содержать один указатель на таблицу виртуальных методов
*/
