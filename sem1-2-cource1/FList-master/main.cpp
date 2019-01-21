//
//  main.cpp
//  FList
//
//  Created by Игорь on 11.03.18.
//  Copyright © 2018 Игорь. All rights reserved.
//

#include "FList.hpp"
#include <locale.h>
/// fo ma boi atoi:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

void tui();

auto case2(FList&) ->void;
auto case3(FList&) ->void;
auto case4(FList&) ->void;
auto case5(FList&) ->void;
void case7(FList&);

int main(int argc, char * argv[]) {
    
    FList list {nullptr};
    
    setlocale(LC_ALL, "rus");
    tui();
    
    if (argc < 2) {
        // empty
    }
    else if (argc == 2){
        // через запятую
        list.insert (atoi(argv[1]));
        
        
        char* input = argv[1];
        for (int i = 0;; i++){
            input = strchr(input, ',') +1;
            list.insert(atoi(input));
            if(strchr(input, ',') == 0) break;
        }
    }
    else{
        // через пробел
        list.insert(atoi(argv[1]));
        for (int i = 2; i < argc ; ++i){
            list.insert(atoi(argv[i]));
        }
    }
    int input;
    while (true) {
        while (!(std::cin >> input) || input < 1 || input > 8) {
            std::cin.clear();
            //cin.get();
            //yell_error();
            //yell_sellect();
        }
        switch(input){
            case 1:
                list.print();
                break;
            case 2:
                case2(list);
                break;
            case 3:
                case3(list);
                break;
            case 4:
                case4(list);
                break;
            case 5:
                case5(list);
                break;
            case 6:
                list.sort();
                break;
            case 7:
                case7(list);
                break;
            case 8:
                list.reverse();
                break;
        }
        tui();
    }
}
void tui()
{
    std::cout << "Выберите одну из операций: " << std::endl;
    std::cout << "1. Распечатать список "      << std::endl;
    std::cout << "2. Добавить элементы в список" <<std::endl;
    std::cout << "3. Удалить элемент" <<std::endl;
    std::cout << "4. Найти позиции элементов" <<std::endl;
    std::cout << "5. Заменить элемент на другой" <<std::endl;
    std::cout << "6. Отсортировать элементы списка" <<std::endl;
    std::cout << "7. Завершить работу программы" <<std::endl;
}

auto case2 (FList &list) ->void {
    string input;
    int temp = 0;
    cout<<"Введите элементы:"<<endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, input);
    int length=int (strlen(input.c_str()));
    for (unsigned int i = 0; i < length; i++)
    if (input[i] == ' ')
    temp++; //temp now has num of spaces
    int *vals = new int[temp];
    vals[0] = atoi(input.c_str());
    temp=1;//temp now is interator for vals
    for (unsigned int i = 0; i < length; i++){
        if (input[0] != ' ')
            input.erase(0,1);
        else
        {
            input.erase(0,1);
            vals[temp] = atoi(input.c_str());
            temp++;
        }
    }
    for (unsigned int i = 0; i < temp; ++i) {
        list.insert(vals[i]);
        list.print();
    }
    delete[] vals;
    }
    
    auto case3 (FList &list) -> void
    {
        cout << "Введите значение:  ";
        int value;
        cin >> value;
        if (cin) {
            if(list.remove(value)) return;
            else cout << "Элемент " << value << " отсутствует." << endl;
            
        }
        else cout << "Введено некорректное значение" <<endl;
        return;
    }
    
    auto case4(FList &list)  ->void
    {
        cout << "Введите значение элемента:  ";
        int val;
        cin >> val;
        if (cin) {
            if(list.find(val)) return;
            else cout << "Элемент " << val << " отсутствует." << endl;
        }
        else cout << "Введено некорректное значение" << endl;
    }
    auto case5(FList &list) -> void
    {
        cout << "Введите позицию и значение:  ";
        int value, pos;
        cin >> pos >> value;
        if (cin) {
            if(list.change(pos, value)) return;
            else cout << "Позиции " << pos << " нет." << endl;
        }
        else cout << "Введено некорректное значение" << endl;
        return;
    }
    void case7 (FList &list) {
        std::cout << "Вы   хотите   выйти   из   программы   ?   (Y/N):";
        std::string input;
        std::cin >> input;
        if ((input == "y") or (input == "yes") or (input == "Yes")
            or (input == "Y") or (input == "YES")) {
            std::cout << "До свидания!" << std::endl;
            exit(0);
        }
    }
