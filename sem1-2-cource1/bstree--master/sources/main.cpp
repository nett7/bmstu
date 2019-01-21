//
//  main.cpp
//  BSTree
//
//  Created by Игорь on 30.03.18.
//  Copyright © 2018 Игорь. All rights reserved.
//

#include <iostream>
#include <locale.h>
#include <stdio.h>
#include "BSTree.hpp"
auto tui() -> void;
auto case2(Tree<int>& tree_) -> void;
auto case3(Tree<int>& tree) -> void;
auto case4(Tree<int>& tree) -> void;
auto case5(Tree<int>& tree) -> void;
auto case6(Tree<int>& tree) -> void;
auto case7(Tree<int>& tree) -> void;
auto case8(Tree<int>& tree) -> void;

int main(int argc, const char* argv[])
{
    Tree <int>a;
    setlocale(LC_ALL, "rus");
    tui();
    //ввод через запятую задание не подразумевает
    if (argc > 2) { //args < 2 => список пуст
        // через пробел
        a.insert(atoi(argv[1]));
        for (int i = 2; i < argc; ++i) {
            a.insert(atoi(argv[i]));
        }
    }
    int input;
    while (true) {
        while (!(std::cin >> input) || input < 1 || input > 8) {
            std::cin.clear();
        }
        switch (input) {
                
            case 1:
                a.print();
                break;
            case 2:
                case2(a);
                break;
            case 3:
                case3(a);
                break;
            case 4:
                case4(a);
                break;
            case 5: //Сохранить дерево в файл
                case5(a);
                break;
            case 6: //Загрузить дерево из файла
                case6(a);
                break;
            case 7: //Проверить наличие узла
                case7(a);
                break;
            case 8: //Завершить работу программы
                case8(a);
                break;
        }
        tui();
    }
}
auto tui() -> void
{
    cout << endl;
    
    cout << " 1. Вывести дерево на экран" << endl;
    cout << " 2. Вывести список узлов дерева" << endl;
    {
        cout << "     a. Прямой обход" << endl;
        cout << "     b. Поперечный обход" << endl;
        cout << "     c. Обратный обход" << endl;
    }
    cout << " 3. Добавить узел в дерево" << endl;
    cout << " 4. Удалить узел из дерева" << endl;
    cout << " 5. Сохранить дерево в файл" << endl;
    cout << " 6. Загрузить дерево из файла" << endl;
    cout << " 7. Проверить наличие узла" << endl;
    cout << " 8. Завершить работу программы" << endl;
    }
    auto case2(Tree<int>& tree_) -> void
    { //ops : direct, symmetric, reverse
        string op;
        if (!((cin >> op) && (op == "a" || op == "b" || op == "c"))) {
            cout << "bad input" << endl;
            return;
        }
        if (tree_.empty()) {
            cout << "пустое дерево" << endl;
            return;
        }
        if (op == "a")
            tree_.list(std::cout, Tree<int>::order::direct);
        if (op == "b")
            tree_.list(std::cout, Tree<int>::order::symmetric);
        if (op == "c")
            tree_.list(std::cout, Tree<int>::order::reverse);
    }
    auto case3(Tree<int>& tree) -> void
    {
        cout << "введите значение: ";
        int val;
        if (cin >> val) {
            try {
                tree.insert(val);
            }
            catch (logic_error e) {
                cout << e.what() << endl;
                return;
            }
        }
        else {
            cout << "неверные данные";
            return;
        }
        cout << "успешно" << endl;
    }
    auto case4(Tree<int>& tree) -> void
    {
        cout << "введите значение: ";
        int val;
        if (cin >> val) {
            try {
                tree.remove(val);
            }
            catch (logic_error e) {
                cout << e.what() << endl;
                return;
            }
        }
        else {
            cout << "неверные данные";
            return;
        }
        cout << "успешно" << endl;
    }
    auto case5(Tree<int>& tree) -> void
    {
        cout << "Введите путь к файлу:  ";
        string filename;
        cin >> filename;
        try {
            if (tree.save(filename)) {
                cout << "успешно" << endl;
                return;
            }
            else {
                cout << "не успешно" << endl;
                return;
            }
        }
        catch (logic_error e) {
            cout << e.what() << endl;
            return;
        }
    }
    auto case6(Tree<int>& tree) -> void
    {
        cout << "Введите путь к файлу:  ";
        string filename;
        cin >> filename;
        try {
            if(tree.load(filename)) {
                cout << "успешно" << endl;
                return;
            }
            else {
                cout << "не успешно" << endl;
                return;
            }
        }
        catch (logic_error e) {
            cout << e.what() << endl;
            return;
        }
    }
    auto case7(Tree<int>& tree) -> void
    {
        int val;
        cout << "Введите значение узла для поиска:" << endl;
        cin >> val;
        if (tree.exists(val))
            cout << "Узел найден" << endl;
        else
            cout << "Узел не найден" << endl;
    }
    auto case8(Tree<int>& tree) -> void
    {
        string vvod;
        cout << "Вы действительно хотите выйти из программы? (Да|Нет)" << endl;
        if ((cin >> vvod) || vvod == "Да")
            exit(0);
    }

