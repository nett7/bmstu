#include <iostream>
#include <string>
#include <locale.h>
#include <iomanip>
#include <cmath>
#include <cstring> //strchr(string, 'sumb') <-- первое вхождение
#include <cstdlib> //exit, atoi
using namespace std;

inline void tui_obesity()
{
    cout << "h    ← "
         << "k    ↑ "
         << "l    → "
         << "j    ↓ " << endl;
}
inline void yell_empty() { cout << "Матрица пустая" << endl; }
inline void yell_wrong_size() { cout << "Неверный   размер" << endl; }
inline void yell_sellect() { cout << "Выберите одну из операций:" << endl; }
inline void yell_error() { cout << "error" << endl; }
inline void yell_result() { cout << "Результат:" << endl; }
inline void yell_enter_matrix() { cout << "Введите данные матрицы:" << endl; }
inline void yell_be_possitive() { cout << "Степень не должна быть отрицательной" << endl; }
inline void yell_integer() { cout << "Степень должна быть целой" << endl; }
inline void tui()
{
    cout << "Выберите одну из операций:" << endl;
    cout << "01. Вывести матрицу (доступно)" << endl;
    cout << "02. Сложить матрицу (доступно)" << endl;
    cout << "03. Умножить матрицу (доступно)" << endl;
    cout << "04. Транспонировать матрицу (доступно)" << endl;
    cout << "05. Расширить матрицу(доступно)" << endl;
    cout << "06. Найти элементы(доступно)" << endl;
    cout << "07. Изменить значение элемента(доступно)" << endl;
    cout << "08. Возвести в степень(доступно)" << endl;
    cout << "09. Вычислить определитель матрицы(тест)" << endl;
    cout << "10. Вычислить обратную матрицу(тест)" << endl;
    cout << "11. Вычислить многочлен матрицы(тест)" << endl;
    cout << "12. Сохранить в файл" << endl;
    cout << "13. Загрузить из файла" << endl;
    cout << "14. Сортировать матрицу" << endl;
    cout << "15. Выйти из программы (доступно)" << endl;
}

int** newarr(int n, int m)
{
    int** a = new int*[n];
    for (int i = 0; i < n; i++)
        a[i] = new int[m];
    return a;
}
double** newarr_double(int n, int m)
{
    double** a = new double*[n];
    for (int i = 0; i < n; i++)
        a[i] = new double[m];
    return a;
}

void matrix_delete(int** a, int n)
{
    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;
}

int** matrix_null(int** a, int n, int m, int what)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a[i][j] = what;
    return a;
}
double** matrix_null_double(double** a, int n, int m, double what)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a[i][j] = what;
    return a;
}

int** matrix_fill(int** a, int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            while (!cin) {
                yell_error();
                cin.clear();
                cin.get();
                cin >> a[i][j];
            }
        }
    return a;
}

void matrix_output(int** a, int n, int m)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}
void matrix_output_double(double** a, int n, int m)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}
void two_matrix_multipication(int a, int b, int c, int** mat1, int** mat2, int** mat_resault)
{
    for (int i = 0; i < a; i++)
        for (int j = 0; j < c; j++)
            for (int k = 0; k < b; k++)
                mat_resault[i][j] += mat1[i][k] * mat2[k][j];
}

int** matrix_power(double vvod, int** a, int n, int m)
{
    if (n != m) {
        yell_wrong_size();
        return a;
    }
    if (vvod < 0) {
        yell_be_possitive();
        return a;
    }
    if (vvod != (int)vvod) {
        yell_integer();
        return a;
    }
    int** resault;
    resault = newarr(n, m);
    resault = matrix_null(resault, n, m, 0);
    switch ((int)vvod) {
    case 0:
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                a[i][j] = 1;
        return a;
        break;
    case 1:
        matrix_delete(resault, n);
        return a;
        break;
    default:
        int** mat2;
        mat2 = newarr(n, n);
        mat2 = matrix_null(mat2, n, n, 0);
        mat2 = a;

        for (int i = 1; i < (int)vvod; i++) {
            two_matrix_multipication(n, n, n, a, mat2, resault);
            mat2 = resault;
        }

        break;
    }
    return resault;
}

int** matrix_integer_multiplication(int** a, int n, int m, int multiplicator)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a[i][j] *= multiplicator;
    return a;
}

int** two_matrix_summation(int** a, int** b, int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a[i][j] += b[i][j];
    return a;
}
inline void case1(int** b, int z, int y, int argc)
{
    if (argc > 1)
        matrix_output(b, z, y);
    else
        yell_empty();
}
int** case2(int** b, int z, int y, int argc, char* argv_one)
{
    if (argc > 1) {

        cout << "Введите матрицу " << argv_one << ":" << endl;
        cin.clear();
        {
            int temp;
            for (int i = 0; i < z; i++) {
                for (int j = 0; j < y; j++) {
                    while (!(std::cin >> temp)) {
                        cin.clear();
                        while (cin.get() != '\n')
                            ;
                        yell_error();
                    }
                    b[i][j] += temp;
                }
            }
        }
        yell_result();
        matrix_output(b, z, y);
    }
    else
        yell_empty();
    return b;
}
int** case3(int** a, int& n, int& m)
{
    cout << "Введите   размер   матрицы: (HINT: матрица должна быть размером " << m << " на x)" << endl;
    char input;
    int n2, m2;
    cin >> n2
        >> input
        >> m2;

    int arov = n, acol = m;
    int** c = newarr(arov, m2);
    c = matrix_null(c, arov, m2, 0);
    if (n2 * m2 == 0) {
        yell_empty();
    }

    else {
        if (n2 != acol) {
            yell_wrong_size();
        }
        else {
            yell_enter_matrix();
            int** b = newarr(n2, m2);
            matrix_fill(b, n2, m2);
            {
                for (int i = 0; i < arov; i++) {
                    for (int j = 0; j < arov + 1; j++) {
                        for (int k = 0; k < acol; k++) {
                            c[i][j] += a[i][k] * b[k][j];
                        }
                    }
                }
            }
            yell_result();
            matrix_output(c, arov, m2);
            m = m2;
            matrix_delete(b, n2);
        }
    }
    return c;
}
int** case4(int** a, int& n, int& m, int z, int y)
{
    if (z * y == 0) {
        yell_empty();
        return 0;
    }

    else {
        int** b = newarr(y, z);
        for (int i = 0; i < y; i++)
            for (int j = z - 1; j > -1; j--)
                b[i][j] = a[j][i];
        n = y;
        m = z;
        return b;
    }
}
double** transpon(double** a, int& n, int& m, int z, int y)
{
    if (z * y == 0) {
        yell_empty();
        return 0;
    }

    else {
        double** b = newarr_double(y, z);
        for (int i = 0; i < y; i++)
            for (int j = z - 1; j > -1; j--)
                b[i][j] = a[j][i];
        n = y;
        m = z;
        return b;
    }
}

int** matrix_obesity(int** a, int& n, int& m)
{
    /*
     h    ←
     k    ↑
     l    →
     j    ↓
     */
    int row = n;
    int col = m;
    int** b = nullptr;
    char input[1];
    cin >> input;
    {
        int ai = 0, aj = 0;
        switch (input[0]) {
        case 'h': /* ← */
            col++;
            m += 1;
            b = newarr(row, col);
            matrix_null(b, row, col, 0);
            for (int i = 0; i < row; i++)
                for (int j = 0; j < col - 1; j++)
                    b[i][j + 1] = a[i][j];

            matrix_output(b, row, col);
            break;
        case 'k': /* ↑ */
            row++;
            n += 1;
            b = newarr(row, col);
            matrix_null(b, row, col, 0);
            for (int i = 0; i < row - 1; i++) {
                for (int j = 0; j < col; j++) {
                    b[i + 1][j] = a[i][j];
                    aj++;
                }
                ai++;
            }
            matrix_output(b, row, col);
            break;
        case 'l': /* → */
            col++;
            m += 1;
            b = newarr(row, col);
            matrix_null(b, row, col, 0);
            for (int i = 0; i < row; i++)
                for (int j = 0; j < col - 1; j++)
                    b[i][j] = a[i][j];

            matrix_output(b, row, col);
            break;
        case 'j': /* ↓ */
            row++;
            n += 1;
            b = newarr(row, col);
            matrix_null(b, row, col, 0);
            for (int i = 0; i < row - 1; i++) {
                for (int j = 0; j < col; j++) {
                    b[i][j] = a[i][j];
                    aj++;
                }
                ai++;
            }
            matrix_output(b, row, col);
            break;
        }
    }
    return b;
}
int** case5(int** a, int& n, int& m)
{
    tui_obesity();
    a = matrix_obesity(a, n, m);
    return a;
}
void case6(int** a, int n, int m)
{
    int vvod;
    cout << "Введите   значение:";
    cin >> vvod;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == vvod) {
                cout << "[" << i << "] [" << j << "]        ";
            }
        }
    }
    cout << endl;
}
void case7(int** a, int n, int m)
{
    cout << "Введите   позицию   ([i][j]):" << endl;
    unsigned int vvodi;
    unsigned int vvodj;
    char skip;
    cin >> skip;
    cin >> vvodi;
    cin >> skip;
    cin >> skip;
    cin >> vvodj;
    cin >> skip;
    if ((vvodi < n) || (vvodj < m)) {
        cin >> a[vvodi][vvodj];
    }
    else {
        yell_error();
    }
}

int** case8(int** a, int n, int m)
{
    double vvod;
    cout << "Введите степень: " << endl;
    cin >> vvod;
    a = matrix_power(vvod, a, n, m);
    return a;
}
////////////////

void matrix_deleter(int** matr, int n, int** temp_matr, int indRow, int indCol)
//функция вычеркивания строки и столбца
{
    int ki = 0;
    for (int i = 0; i < n; i++) {
        if (i != indRow) {
            for (int j = 0, kj = 0; j < n; j++) {
                if (j != indCol) {
                    temp_matr[ki][kj] = matr[i][j];
                    kj++;
                }
            }
            ki++;
        }
    }
}
//////////////////

int determ(int** a, int n)
{
    int temp = 0;
    int k = 1;
    if (n < 1) {
        cout << "Не верный размер матрицы!!!" << endl;
        return 0;
    }
    else if (n == 1)
        temp = a[0][0];
    else if (n == 2)
        temp = a[0][0] * a[1][1] - a[1][0] * a[0][1];
    else {
        for (int i = 0; i < n; i++) {
            int m = n - 1;
            int** temp_matr = new int*[m];
            for (int j = 0; j < m; j++)
                temp_matr[j] = new int[m];
            matrix_deleter(a, n, temp_matr, 0, i);
            temp = temp + k * a[0][i] * determ(temp_matr, m);
            k = -k;
            matrix_delete(temp_matr, m);
        }
    }
    return temp;
}

void case9(int** a, int n, int m)
{
    if (n == m) {
        int determinant;
        determinant = determ(a, n);
        yell_result();
        cout << determinant << endl;
    }
    else {
        yell_error();
    }
}

int** matrix_invertible(int** a, int n, int m)
{
    double** obr_matr;
    obr_matr = newarr_double(n, m);
    obr_matr = matrix_null_double(obr_matr, n, m, 0);
    if (n == m) {
        int determinant = determ(a, n);
        if (determinant != 0) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    int m = n - 1;
                    int** temp_matr = new int*[m];
                    for (int k = 0; k < m; k++)
                        temp_matr[k] = new int[m];
                    matrix_deleter(a, n, temp_matr, i, j);
                    obr_matr[i][j] = (pow(-1.0, i + j + 2) * determ(temp_matr, m) / determinant);
                    matrix_delete(temp_matr, m);
                }
            }
            obr_matr = transpon(obr_matr, n, m, n, m);
        }
        else {
            cout << "Determinant = 0" << endl;
            yell_error();
            return a;
        }
    }
    matrix_output_double(obr_matr, n, n);

    return a;
}

int** case10(int** a, int n, int m)
{
    if (n != m) {
        yell_wrong_size();
        return a;
    }
    else if (n * m == 0) {
        yell_empty();
        return a;
    }
    else {
        a = matrix_invertible(a, n, m);
        return a;
    }
}

int** case11(int** a, int n, int m)
{
    cout << "Вычислить многочлен матрицы" << endl;
    if (n != m) {
        yell_wrong_size();
        return a;
    }
    cout << "Введите степень многочлена:" << endl;
    double power;
    cin >> power;
    if (power < 0) {
        yell_be_possitive();
        return a;
    }
    if (power != (int)power) {
        yell_integer();
        return a;
    }
    int** resault;
    resault = newarr(n, m);
    resault = matrix_null(resault, n, n, 1);
    int** a_temp;
    a_temp = newarr(n, m);
    a_temp = matrix_null(a_temp, n, n, 0);
    cout << "enter a[0]: ";
    int a_multiplicator;
    cin >> a_multiplicator;
    resault = matrix_null(resault, n, m, a_multiplicator);

    for (int i = 1; i <= (int)power; i++) {
        cout << "enter a[" << i << "]: ";
        cin >> a_multiplicator;
        a_temp = matrix_power((double)i, a, n, m);
        a_temp = matrix_integer_multiplication(a_temp, n, m, a_multiplicator);
        resault = two_matrix_summation(a_temp, resault, n, m);
    }
    matrix_delete(a_temp, n);
    return resault;
}

int main(int argc, char* argv[])
{
    cout << argc;
    setlocale(LC_ALL, "rus");
    int input;
    tui();
    int z = 0, y = 0;

    if (argc > 1) {
        z = atoi(argv[1]);
        y = atoi(strchr(argv[1], 'x') + 1);
    }

    int** b = newarr(z, y);

    if ((argc != 3) && (z * y != 0)) {
        int k = 2;
        for (int i = 0; i < z; i++) {
            for (int j = 0; j < y && k < argc; j++, k++) {
                b[i][j] = atoi(argv[k]);
            }
        }
    }
    else {
        char* symbols = argv[2];
        for (int i = 0; i < z; i++) {
            for (int j = 0; j < y; j++) {
                b[i][j] = atoi(symbols);
                if (strchr(symbols, ',') == 0)
                    break;
                symbols = strchr(symbols, ',') + 1;
            }
            if (strchr(symbols, ',') == 0)
                break;
        }
    }
    for (int i = argc - 2; i < z * y; i++)
        b[i / y][i % y] = 0;

    while (true) {
        while (!(cin >> input) || input < 1 || input > 15) {
            cin.clear();
            cin.get();
            yell_error();
            yell_sellect();
        }
        switch (input) {
        case 1:
            case1(b, z, y, argc);
            break; //plain output
        case 2:
            b = case2(b, z, y, argc, argv[1]);
            break; //summint argc, char* argv_one
        case 3:
            b = case3(b, z, y);
            break;
        case 4:
            b = case4(b, z, y, z, y);
            break; //transponce
        case 5:
            b = case5(b, z, y);
            break;
        case 6:
            case6(b, z, y);
            break;
        case 7:
            case7(b, z, y);
            break;
        case 8:
            b = case8(b, z, y);
            break;
        case 9:
            case9(b, z, y);
            break;
        case 10:
            b = case10(b, z, y);
            break;
        case 11:
            b = case11(b, z, y);
            break;
        case 15:
            cout << "Вы   хотите   выйти   из   программы   ?   (Y/N):";
            string input;
            cin >> input;
            if ((input == "y") or (input == "yes") or (input == "Yes")
                or (input == "Y") or (input == "YES")) {
                cout << "До свидания!" << endl;
                matrix_delete(b, z);
                exit(0);
            }
            break;
        }
        tui();
    }
    return 0;
}
