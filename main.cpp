#include <iostream>
#include <chrono>

using namespace std;

// Функції для вимірювання часу виконання операцій

template <typename T>
double add_test(T a, T b, int n)
{
	auto start = chrono::high_resolution_clock::now();
	for (int i = 0; i < n; i++) {
    	a = a + b;
	}
	auto end = chrono::high_resolution_clock::now();
	return chrono::duration_cast<chrono::nanoseconds>(end - start).count();
}

template <typename T>
double sub_test(T a, T b, int n)
{
	auto start = chrono::high_resolution_clock::now();
	for (int i = 0; i < n; i++) {
    	a = a - b;
        a = a - b;
        a = a - b;
        a = a - b;
        a = a - b;
        a = a - b;
        a = a - b;
        a = a - b;
        a = a - b;
        a = a - b;
        a = a - b;
        a = a - b;
        a = a - b;
        a = a - b;
        a = a - b;
        a = a - b;
	}
	auto end = chrono::high_resolution_clock::now();
	return chrono::duration_cast<chrono::nanoseconds>(end - start).count();
}

template <typename T>
double mul_test(T a, T b, int n)
{
	auto start = chrono::high_resolution_clock::now();
	for (int i = 0; i < n; i++) {
    	a = a * b;
        a = a * b;
        a = a * b;
        a = a * b;
        a = a * b;
        a = a * b;
        a = a * b;
        a = a * b;
        a = a * b;
        a = a * b;
        a = a * b;
        a = a * b;
        a = a * b;
        a = a * b;
        a = a * b;
        a = a * b;
	}
	auto end = chrono::high_resolution_clock::now();
	return chrono::duration_cast<chrono::nanoseconds>(end - start).count();
}

template <typename T>
double div_test(T a, T b, int n)
{
	auto start = chrono::high_resolution_clock::now();
	for (int i = 0; i < n; i++) {
    	a = a / b;
        a = a / b;
        a = a / b;
        a = a / b;
        a = a / b;
        a = a / b;
        a = a / b;
        a = a / b;
        a = a / b;
        a = a / b;
        a = a / b;
        a = a / b;
        a = a / b;
        a = a / b;
        a = a / b;
        a = a / b;
        a = a / b;
        a = a / b;
        a = a / b;
        a = a / b;
        a = a / b;
	}
	auto end = chrono::high_resolution_clock::now();
	return chrono::duration_cast<chrono::nanoseconds>(end - start).count();
}

// Функції для виведення результатів тестів
string line_diagram(int percent)
{
	string diagram;
	for (int i = 0; i < 100/8; i++) {
        	if (i < percent/8){
            	diagram += "X";
        	}else{
            	diagram += " ";
        	}
	}
	return diagram;
}
template <typename T>
void print_results(int n)
{
	T a = 151515518751518777;
	T b = 85957778950213;

	double add_time = add_test(a, b, n);
	double sub_time = sub_test(a, b, n);
	double mul_time = mul_test(a, b, n);
	double div_time = div_test(a, b, n);

	double add_ops = n / (add_time / n);
	double sub_ops = n / (sub_time / n);
	double mul_ops = n / (mul_time / n);
	double div_ops = n / (div_time / n);

// Знаходимо найшвидшу операцію та відсотки відносно неї
double fastest = add_ops;
if (sub_ops > fastest) {
	fastest = sub_ops;
}
if (mul_ops > fastest) {
	fastest = mul_ops;
}
if (div_ops > fastest) {
	fastest = div_ops;
}

int add_percent = (int)(add_ops / fastest * 100);
int sub_percent = (int)(sub_ops / fastest * 100);
int mul_percent = (int)(mul_ops / fastest * 100);
int div_percent = (int)(div_ops / fastest * 100);

// Виводимо результати у табличному вигляді
cout << "Додавання + \t\t" << typeid(T).name() << "\t\t\t" << add_ops << "\t\t"  << line_diagram(add_percent) << "\t\t" << add_percent << endl;
cout << "Віднімання - \t\t" << typeid(T).name() << "\t\t\t" << sub_ops << "\t\t" << line_diagram(sub_percent) << "\t\t" << sub_percent << endl;
cout << "Множення * \t\t" << typeid(T).name() << "\t\t\t" << mul_ops << "\t\t"  << line_diagram(mul_percent) << "\t\t" << mul_percent << endl;
cout << "Ділення / \t\t" << typeid(T).name() << "\t\t\t" << div_ops << "\t\t" << line_diagram(div_percent) << "\t\t" << div_percent << endl;
cout << "-----------------------------------------------------------------------------------------------------\n";
}

int main()
{
	cout << "Операція\t\tТип данних\t\tОп/с\t\t\t\tДіаграма, %\n";
	cout << "=====================================================================================================\n";
	// Викликаємо функцію print_results для кожного типу даних
	print_results<char>(100000000);
	print_results<int>(100000000);
	print_results<long>(100000000);
	print_results<float>(100000000);
	print_results<double>(100000000);
	cout << endl;

	return 0;
}
