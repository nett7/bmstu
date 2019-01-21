### Задачи

1. Реализовать класс `Queue`:

```cpp
// queue.hpp                                        | // main.cpp
                                                    |
class Queue {                                       | #include <queue.hpp>
                                                    |
public:                                             | int main() {
                                                    |
    typedef int type;                               |   Queue q1;
                                                    |
    Queue();                                        |   Queue q2 = {1, 2, 3, 4};
                                                    |
    Queue(std::initialer_list<type> list);          |   Queue q3{q2};
                                                    |
    Queue(const Queue& q);                          |   cout << q2 << endl;
                                                    |   cout << q3 << endl;
    auto swap(Queue& q) -> void;                    |
                                                    |   q1.swap(q3);
    auto operator=(const Queue& q);                 |   cout << q1 << endl;
                                                    |
    auto empty() -> bool;                           |   cout << boolalpha
                                                    |        << q3.empty();
    auto size() -> size_t;                          |
                                                    |   cout << q1.size() << endl;
    auto push(type) -> void;                        |
                                                    |   q3.push(5);
    auto pop() -> void;                             |   cout << q3 << endl;
                                                    |
    auto front() -> type&;                          |   ofstream output{ "queue.bin" };
                                                    |   output << q3;
    auto back() -> type&;                           |
                                                    |   Queue q4;
    bool operator==(const Queue& q);                |   ifstream input{ "queue.bin" };
                                                    |   input >> q4;
    friend                                          |
    auto operator<<(ostream&, Queue&) -> ostream&;  |   cout << (q4 == q3) << endl;
                                                    |
    friend                                          |   cout << q4.front() << endl;
    auto operator>>(istream&, Queue&) -> istream&;  |   cout << q5.back() << endl;
                                                    |
    ~Queue();                                       |   q4.pop();
                                                    |   cout << q4 << endl;
private:                                            |
    ForwardList* list;                              |   q4.front() = 6;
};                                                  | }
```

2. Заполнить отчет

```ShellSession
$ git clone https://github.com/<username>/queue
$ cd queue
$ g++ main.cpp queue.cpp -I. -std=c++11 -o queue-example
$ ./queue-example
...
```

### Требования

- Класс `Queue` сделать шаблонным
- Пометить все необходимые методы квалификатором `const`
- Использовать списки инициализации, как для полей, так и для конструкторов
- Избежать дублирование кода
