class Complex {
//комплексное число a + ib
//комплекстносопряженное
public:
typedef double type; //tupedef <old type> <new type> -- type definition
Complex();//конструктор по умолчанию
Complex(type a); // коструктор с параметром
Complex(type a, type b);
Complex(const Complex& c);

auto swap(Complex&) -> void;
auto operator=(const Complex& c) -> Complex&; // опператор присваивания с семантикой копирования; изменить старое значение копией нового;
/*
operator=(const Complex& c) -> Complex& {
    this -> swap (Complex{c});
    return *this;
}
//так нужно реализовывать присаивание
*/
/*
template<template T>
class Complex {


}
...
int main() {
Complex<int> с1; //операция инстанцирования
}

*/
auto operator+(const Complex& c) -> Complex;
auto operator-(const Complex& c) -> Complex;
auto operator*(const Complex& c) -> Complex;
auto operator/(const Complex& c) -> Complex;

auto operator!() -> Complex; //для комплексносопряжонного

auto operator==(const Complex& c) -> bool;
auto operator!=(const Complex& c) -> bool;

explicit operator type(); // из пользовательского в встроенный; для обратной операции использовать конструктор

auto operator[](size_t index) -> type;

friend
auto operator>>(istream&, Complex c) -> istream;
friend
auto operator>>(ostream&, const Complex c) -> ostream;

static Complex from_string(const std::string& string);

~Complex();
private:
    std::pair<type, type>* pair;

}
