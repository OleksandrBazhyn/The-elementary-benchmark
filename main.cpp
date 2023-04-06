#include <iostream>
#include <chrono>
#include <Windows.h>

using namespace std;

int a = 5454548515;
int b = 81215487;
double TestResults[5][4];

// Функції для вимірювання часу виконання операцій
template <typename T>
double add_test(T a, T b, int n)
{
    int c = 0;
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < n; i++) {
        c = a + b;
    }
    auto end = chrono::high_resolution_clock::now();
    return n / (static_cast<double>(chrono::duration_cast<chrono::nanoseconds>(end - start).count()) / n);
}

template <typename T>
double sub_test(T a, T b, int n)
{
    int c = 0;
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < n; i++) {
        c = a - b;
    }
    auto end = chrono::high_resolution_clock::now();
    return n / (static_cast<double>(chrono::duration_cast<chrono::nanoseconds>(end - start).count()) / n);
}

template <typename T>
double mul_test(T a, T b, int n)
{
    int c = 0;
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < n; i++) {
        c = a * b;
    }
    auto end = chrono::high_resolution_clock::now();

    return n / (static_cast<double>(chrono::duration_cast<chrono::nanoseconds>(end - start).count()) / n);
}

template <typename T>
double div_test(T a, T b, int n)
{
    int c = 0;
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < n; i++) {
        c = a / b;
    }
    auto end = chrono::high_resolution_clock::now();
    return n / (static_cast<double>(chrono::duration_cast<chrono::nanoseconds>(end - start).count()) / n);
}

void Test(int n) {
    TestResults[0][0] = add_test<char>(a, b, n);
    TestResults[0][1] = sub_test<char>(a, b, n);
    TestResults[0][2] = mul_test<char>(a, b, n);
    TestResults[0][3] = div_test<char>(a, b, n);

    TestResults[1][0] = add_test<int>(a, b, n);
    TestResults[1][1] = sub_test<int>(a, b, n);
    TestResults[1][2] = mul_test<int>(a, b, n);
    TestResults[1][3] = div_test<int>(a, b, n);

    TestResults[2][0] = add_test<long>(a, b, n);
    TestResults[2][1] = sub_test<long>(a, b, n);
    TestResults[2][2] = mul_test<long>(a, b, n);
    TestResults[2][3] = div_test<long>(a, b, n);

    TestResults[3][0] = add_test<float>(a, b, n);
    TestResults[3][1] = sub_test<float>(a, b, n);
    TestResults[3][2] = mul_test<float>(a, b, n);
    TestResults[3][3] = div_test<float>(a, b, n);

    TestResults[4][0] = add_test<double>(a, b, n);
    TestResults[4][1] = sub_test<double>(a, b, n);
    TestResults[4][2] = mul_test<double>(a, b, n);
    TestResults[4][3] = div_test<double>(a, b, n);
}

// Функції для виведення результатів тестів
string line_diagram(int percent)
{
    string diagram;
    for (int i = 0; i < 100 / 5; i++) {
        if (i < percent / 5) {
            diagram += "X";
        }
        else {
            diagram += " ";
        }
    }
    return diagram;
}

template <typename T>
void print_results(double fastest)
{
    const char* typeName = typeid(T).name();
    int intOfType = -1;
    switch (typeName[0]) {
    case 'c':
        intOfType = 0;
        break;
    case 'i':
        intOfType = 1;
        break;
    case 'l':
        intOfType = 2;
        break;
    case 'f':
        intOfType = 3;
        break;
    case 'd':
        intOfType = 4;
        break;
    default:
        break;
    }

    int add_percent = (int)(TestResults[intOfType][0] * 100 / fastest);
    int sub_percent = (int)(TestResults[intOfType][1] * 100 / fastest);
    int mul_percent = (int)(TestResults[intOfType][2] * 100 / fastest);
    int div_percent = (int)(TestResults[intOfType][3] * 100 / fastest);

    // Виводимо результати у табличному вигляді
    cout << "Додавання + \t\t" << typeName << "\t\t\t" << TestResults[intOfType][0] << "\t\t" << line_diagram(add_percent) << "\t" << add_percent << endl;
    cout << "Віднімання - \t\t" << typeName << "\t\t\t" << TestResults[intOfType][1] << "\t\t" << line_diagram(sub_percent) << "\t" << sub_percent << endl;
    cout << "Множення * \t\t" << typeName << "\t\t\t" << TestResults[intOfType][2] << "\t\t" << line_diagram(mul_percent) << "\t" << mul_percent << endl;
    cout << "Ділення / \t\t" << typeName << "\t\t\t" << TestResults[intOfType][3] << "\t\t" << line_diagram(div_percent) << "\t" << div_percent << endl;
    cout << "-----------------------------------------------------------------------------------------------------\n";
}

int TheFasterOper()
{
    // Знаходимо найшвидшу операцію та відсотки відносно неї
    double fastest = TestResults[0][0];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
            if (TestResults[i][j] > fastest) {
                fastest = TestResults[i][j];
            }
    }

    return fastest;
}

int main()
{
    SetConsoleOutputCP(1251);
    cout << "Операція\t\tТип данних\t\tОп/с\t\t\t\tДіаграма, %\n";
    cout << "=====================================================================================================\n";
    int countOfOperations = 99990000;
    Test(countOfOperations);
    double fastest = TheFasterOper();
    
    // Викликаємо функцію print_results для кожного типу даних
    print_results<char>(fastest);
    print_results<int>(fastest);
    print_results<long>(fastest);
    print_results<float>(fastest);
    print_results<double>(fastest);
    cout << endl;

    return 0;
}
