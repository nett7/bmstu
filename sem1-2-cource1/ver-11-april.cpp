#include <iostream>
#include <string>

using std::string;

struct Person {
    string first_name;
    string middle_name;
    string last_name;
    Person ( string first_name,
        string middle_name,
        string last_name)
            :first_name_{first_name},
            middle_name_{middle_name},
            last_name_{last_name}
            {
                std::cout << "Person()" << std::endl;
            }
    auto virtual print() -> void{  // if metot re introdused it will passed on
        std::cout << "first_name" << std::endl;
        std::cout << "middle_name" << std::endl;
        std::cout << "last_name" << std::endl;
    }
    virtual ~Person() = default; // same as empty body but nicer

};
struct Student : public Person{
    /*
        couse of public inherece this will look like :

        string first_name_;
        string middle_name_;
        string last_name_;
    */
    string group;
    Student (string group,
        string first_name,
        string middle_name,
        string last_name)
            :
            /*first_name_{first_name},
            middle_name_{middle_name},
            last_name_{last_name},*/
            Person{first_name, middle_name, last_name},
            group_{group}
            {
                std::cout << Student() << std::endl;
            }

    auto print() -> void override{  // override is a memo overritten metods of virtual metods of parent class
            std::cout << first_name << std::endl;
            std::cout << middle_name << std::endl;
            std::cout << last_name << std::endl;
            std::cout << group<< std::endl;
    }
    Student (const Student& student);
    auto operator =(const Student& student) ->Student&{
        return *this; // * returns link not type if not stated something else
    }
    ~Student() {
        std::cout <<"~Student::Student"<<std::endl;
    }
};

int main () {
    Person p = {"Oleg", "Petrovich", "Sidorov"};
    Student* student1 = new Student{"IU8-24", "Oleg", "Petrovich", "Sidorov"};
    student1 -> print(); // Student :: print()

    Person* student2 = new Student{"IU8-24", "Oleg", "Petrovich", "Sidorov"};

    /*
                        \4-8 bites/
                      -------------------                     -----------------------                       -------------------
student2    --->     |       vrptr       |         -------   |  (x) Person::print()  |      ---------->    |  Student::print() |
                      -------------------        ---          -----------------------                       -------------------
                |    |                   |           |       |  (x) Person::~Person  |                     | Student::~Student |
                |     -------------------            |        -----------------------                       -------------------
                |    |                   |           |   Person
                |     -------------------            |
                |    |                   |           |
                |     -------------------        ===
                |    |                   |           |   group
                |     -------------------        ---
                \/


p -------------->  -------------------                           -------------------
                  |       vrptr       |         ----------->    |   Person::print() |
                   -------------------                           -------------------
                  |                   |                         |  Person::~Person  |
                   -------------------                           -------------------
                  |                   |
                   -------------------
                  |                   |
                   -------------------

при поли морфизме сначала вызывается леве потом правые, при этом могет идти переопределение
таблицы вирт методов и методов внутри класса

    */
    student2 -> print(); // Person :: print()


}
