




auto swap(Complex&) -> void{

}
auto operator=(const Complex& c) -> Complex&{
    this -> swap (Complex{c});
    return *this;
}
auto operator+(const Complex& c) -> Complex {
    Complex res;
    res.first = this->first + c.first;
    res.second = this->second + s.second;
    return res;
}
auto operator-(const Complex& c) -> Complex{
    Complex res;
    res.first = this->first - c.first;
    res.second = this->second - s.second;
    return res;
}
auto operator*(const Complex& c) -> Complex{
    Complex res;
    res.first = this->first * c.first;
    res.second = this->second * s.second;
    return res;
}
auto operator/(const Complex& c) -> Complex{
    Complex res;
    res.first = this->first / c.first;
    res.second = this->second / s.second;
    return res;
}
